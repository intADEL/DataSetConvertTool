#include "xmlyoloconvert.h"

xmlyoloconvert::xmlyoloconvert()
{

}
void xmlyoloconvert::setConfig(string labelDir,string imgsDir, string yoloConvDir,string labelMap){
    this->imgsDir= imgsDir;
    this->labelDir= labelDir;
    this->labelMap=labelMap;
    this->yoloConvDir= yoloConvDir;
}

void xmlyoloconvert::run(){
    std::vector<fs::path> xmlFiles;
    xmlFiles=get_all(this->labelDir,".xml");
    struct objectStruct{
        string name;
        cv::Size imgSize;
        cv::Rect Rect;
    };
    for(size_t i=0;i<xmlFiles.size();i++){
        vector<objectStruct> objects;
//        cout<<xmlFiles[i].string()<<endl;
        xml_document doc;
        // load the XML file
        if (!doc.load_file(xmlFiles[i].string().c_str()))
           cout<<"18\n";
        xml_node tools = doc.child("annotation");//.child("object");
        objectStruct os;
        os.imgSize=cv::Size2i(tools.child("size").child("width").text().as_int(),
                              tools.child("size").child("height").text().as_int());
        for (pugi::xml_node tool: tools.children("object"))
        {
            os.name=tool.child("name").text().get();
                cv::Point pt1=cv::Point2d(tool.child("bndbox").child("xmin").text().as_int(),
                                          tool.child("bndbox").child("ymin").text().as_int());
                cv::Point pt2=cv::Point2d(tool.child("bndbox").child("xmax").text().as_int(),
                                          tool.child("bndbox").child("ymax").text().as_int());
                os.Rect=cv::Rect(pt1,pt2);
                objects.push_back(os);
            }
    //    cv::Mat img=cv::imread(this->imgsDir);
        std::string token = xmlFiles[i].filename().string().substr(0, xmlFiles[i].filename().string().find("."));
        string filename=this->yoloConvDir+"/"+token+".txt";
        if(objects.size()>1)
            continue;
        for(size_t i=0;i<objects.size();i++){
            double c_x=static_cast<float>(static_cast<float>(objects[i].Rect.width/2)+objects[i].Rect.x)/static_cast<float>(objects[i].imgSize.width);
            double c_y=static_cast<float>(static_cast<float>(objects[i].Rect.height/2)+objects[i].Rect.y)/static_cast<float>(objects[i].imgSize.height);
            double w=static_cast<float>(objects[i].Rect.width)/static_cast<float>(objects[i].imgSize.width);
            double h=static_cast<float>(objects[i].Rect.height)/static_cast<float>(objects[i].imgSize.height);
            string Data=to_string(labeltoNum(objects[i].name))
                    +" "+to_string(c_x)
                    +" "+to_string(c_y)
                    +" "+to_string(w)
                    +" "+to_string(h);
            cout<<"Data: "<<Data<<endl;
            writeData(filename,Data);
            if(labeltoNum(objects[i].name)>0){
                string Data=to_string(0)
                        +" "+to_string(c_x)
                        +" "+to_string(c_y)
                        +" "+to_string(w)
                        +" "+to_string(h);
                cout<<"Data: "<<Data<<endl;
                writeData(filename,Data);
            }
        }
    }

}
int xmlyoloconvert::labeltoNum(string label){
    CSVReader reader(this->labelMap);
    // Get the data from CSV File
    std::vector<std::vector<std::string> > dataList = reader.getData();
    // Print the content of row by row on screen
    for(std::vector<std::string> vec : dataList)
    {
//            cout<<"label map"<<":"<<vec[0]<<" label:"<<label<<endl;
        if(strcmp(vec[0].c_str(),label.c_str())==0){
            return stoi(vec[1]);
            break;
        }
     }
     return -1;
}
void xmlyoloconvert::writeData(string &filename, string Data){
    std::ofstream outfile;
    outfile.open(filename, std::ios_base::app);
    outfile <<Data<<endl;
    outfile.close();
}


std::vector<fs::path> xmlyoloconvert::get_all(fs::path const & root, std::string const & ext)
{
    std::vector<fs::path> paths;
    if (fs::exists(root) && fs::is_directory(root))
    {
        for (auto const & entry : fs::recursive_directory_iterator(root))
        {
            if (fs::is_regular_file(entry) && entry.path().extension() == ext)
                paths.emplace_back(entry.path());
        }
    }
    return paths;
}
