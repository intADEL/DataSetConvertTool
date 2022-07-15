#include "platecrop.h"
#include <definition.h>
using namespace boost::filesystem;

platecrop::platecrop()
{

}
int platecrop::init(string labelfile,string imgsDir,string labelDir,string cropImgDir, string labelMap,int method){
    this->labelfile=labelfile;
    this->labelDir=labelDir;
    this->imgsDir=imgsDir;
    this->cropImgDir=cropImgDir;
    this->labelMap=labelMap;
    this->method=method;
}

int platecrop::run(){
    string imgName;
    if(this->method==1){
        //in one file , ehtemalan csv
    string labelName;
    string temp;
    string imgnameWithoutFormat;
    std::vector<string> vec,vec2,vec3;
    CSVReader reader(labelfile," ");
    std::vector<std::vector<std::string> > dataList = reader.getData();
    for(size_t i=0;i<dataList.size();i++)
    //for(std::vector<std::string> vec : dataList)
    {
        imgName=dataList[i][0].substr(0, dataList[i][0].size()-1);
//        cout<<"image name: "<<imgName<<endl;
        labelName=dataList[i][1];
//        cout<<"label name: "<<labelName<<endl;
        temp=dataList[i][2].substr(1, dataList[i][2].size()-2);
        boost::algorithm::split(vec, temp, boost::is_any_of(","));
        cout<<"x,y: "<<vec[0]<<","<<vec[1]<<endl;
        temp=dataList[i][4].substr(1, dataList[i][4].size()-2);
        boost::algorithm::split(vec2, temp, boost::is_any_of(","));
        cout<<"x,y: "<<vec2[0]<<","<<vec2[1]<<endl;
        cv::Rect roi=cv::Rect2i(cv::Point2i(stoi(vec[0]),stoi(vec[1])),cv::Point2i(stoi(vec2[0]),stoi(vec2[1])));
        boost::algorithm::split(vec3, imgName, boost::is_any_of("."));
        imgnameWithoutFormat=vec3[0];
        if(boost::filesystem::exists(imgsDir+'/'+imgName)){
            cv::Mat img=cv::imread(imgsDir+'/'+imgName);
            cv::Mat objCroped=img(roi);
//            cv::imshow("crop",objCroped);
            int obj_num=0;
            string filename_txt;
            string token_plus_num,Data;
            bool existBefore=false;
            do {
                token_plus_num=imgnameWithoutFormat+to_format(obj_num++);
                filename_txt=labelDir+"/"+token_plus_num+".txt";
                }
            while(boost::filesystem::exists(filename_txt));
            cv::imwrite(this->cropImgDir+"/"+token_plus_num+".jpg",objCroped);
            Data=to_string(labeltoNum(labelName))
                    +" "+to_string(0.5)
                    +" "+to_string(0.5)
                    +" "+to_string(1.000000)
                    +" "+to_string(1.000000);
            string txtAddr=this->labelDir+"/"+token_plus_num+".txt";
            writeData(txtAddr,Data);
//            cv::waitKey();

        }
    }
    }
    if(this->method==2){
        // directory
        path p(this->imgsDir);
        if(is_directory(p)) {
            std::cout << p << " is a directory containing:\n";
            string Data,token_plus_num;
            vector<string> vec;
            for(auto& entry : boost::make_iterator_range(directory_iterator(p), {}))
            {
                std::vector<string> pathVec;
                boost::algorithm::split(pathVec, entry.path().string(), boost::is_any_of("/"));
                std::cout << pathVec.back() << "\n";
                copy_file(entry.path().string(),this->cropImgDir+"/"+pathVec.back(),copy_option::overwrite_if_exists);
                Data=to_string(labeltoNum(this->labelfile))
                        +" "+to_string(0.5)
                        +" "+to_string(0.5)
                        +" "+to_string(1.000000)
                        +" "+to_string(1.000000);
                boost::algorithm::split(vec, pathVec.back(), boost::is_any_of("."));
                string txtAddr=this->labelDir+"/"+vec[0]+".txt";
                writeData(txtAddr,Data);
            }
        }
    }
    if(this->method==3){
        //directory txt yolo => only crop plate
    string labelName;
    string temp;
    string imgnameWithoutFormat;
    std::vector<string> vec,vec2,vec3;
    std::vector<fs::path> txtFiles;
    txtFiles=get_all(this->labelDir,".txt");
    for(size_t i=0;i<txtFiles.size();i++){
        imgName=txtFiles[i].filename().string().substr(0, txtFiles[i].filename().string().find(".")); //dataList[i][0].substr(0, dataList[i][0].size()-1);
        if(boost::filesystem::exists(imgsDir+'/'+imgName+".jpg")){
    CSVReader reader(txtFiles[i].string()," ");
    cout<<"File:\t"<<txtFiles[i].string()<<endl;
    std::vector<std::vector<std::string> > dataList = reader.getData();
    for(size_t i=0;i<dataList.size();i++)
    //for(std::vector<std::string> vec : dataList)
    {
//        cout<<"image name: "<<imgName<<endl;

            labelName=dataList[i][0];
    //        cout<<"label name: "<<labelName<<endl;
            double roi_x=stod(dataList[i][1]);
            double roi_y=stod(dataList[i][2]);
            double roi_w=stod(dataList[i][3]);
            double roi_h=stod(dataList[i][4]);
            cv::Mat img=cv::imread(imgsDir+'/'+imgName+".jpg");
//            cout<<"image file:\t"<<imgsDir+'/'+imgName+".jpg"<<endl;
//            cout<<"text file: "<<txtFiles[i].filename().string()<<endl;
//            cout<<"datalist: "<<dataList[0][0]<<endl;
//            cout<<"(label,x,y,w,h): "<<labelName<<roi_x<<roi_y<<roi_w<<roi_h<<endl;
            cv::Rect roi=cv::Rect(static_cast<int>((roi_x-(roi_w/2))*img.size().width)
                                  ,static_cast<int>((roi_y-(roi_h/2))*img.size().height)
                                  ,static_cast<int>(roi_w*img.size().width)
                                  ,static_cast<int>(roi_h*img.size().height));
//            cv::rectangle(img,roi,cv::Scalar(0,0,255));
//            cv::namedWindow("img",cv::WINDOW_NORMAL);
//            cv::imshow("img",img);
//            cv::waitKey();
            cv::Mat objCroped=img(roi);
//            cv::imshow("crop",objCroped);
//            cv::waitKey();
            int obj_num=0;
            string filename_jpg;
            string token_plus_num,Data;
            bool existBefore=false;
            do {
                token_plus_num=labelName+"_B_"+to_format(obj_num++);
                filename_jpg=cropImgDir+"/"+token_plus_num+".jpg";
                }
            while(boost::filesystem::exists(filename_jpg));
            cv::imwrite(this->cropImgDir+"/"+token_plus_num+".jpg",objCroped);
//            Data=to_string(labeltoNum(labelName))
//                    +" "+to_string(0.5)
//                    +" "+to_string(0.5)
//                    +" "+to_string(1.000000)
//                    +" "+to_string(1.000000);
//            string txtAddr=this->labelDir+"/"+token_plus_num+".txt";
//            writeData(txtAddr,Data);
//            cv::waitKey();

        }
    }
    }
    }
}

int platecrop::labeltoNum(string label){
    CSVReader reader(this->labelMap);
        // Get the data from CSV File
        std::vector<std::vector<std::string> > dataList = reader.getData();
        // Print the content of row by row on screen
        for(std::vector<std::string> vec : dataList)
        {
//            cout<<label<<":"<<vec[1]<<endl;
            if(strcmp(vec[0].c_str(),label.c_str())==0){
                return stoi(vec[1]);
                break;
            }
        }
        return -1;
}
void platecrop::writeData(string &filename, string Data){
    std::ofstream outfile;

    outfile.open(filename, std::ios_base::app);
    outfile <<Data<<endl;
    outfile.close();
}
std::vector<fs::path> platecrop::get_all(fs::path const & root, std::string const & ext)
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
