#include "toyoloconvert.h"
#include <string.h>
toyoloconvert::toyoloconvert()
{

}
void toyoloconvert::setConfig(string labeldir, string imgdir, string labelmap, std::vector<string> labeladdrs){
    labelDir=labeldir;
    imgsDir=imgdir;
    labelMap=labelmap;
    labelsAddr=labeladdrs;
}
void toyoloconvert::convert(){
    for(size_t i=0;i<this->labelsAddr.size();i++)
    {
    CSVReader reader(labelsAddr[0]);
        // Get the data from CSV File
        std::vector<std::vector<std::string> > dataList = reader.getData();
        // Print the content of row by row on screen
        for(size_t i=1;i<dataList.size();i++)
//        for(std::vector<std::string> vec : dataList)
        {
            // Print File Name:
            cout<<dataList[i][0];
            std::string token = dataList[i][0].substr(0, dataList[i][0].find("."));
            string filename=labelDir+"/"+token+".txt";
            int classNum=labeltoNum(dataList[i][3]);
            if(classNum==-1){
                cout<<"Error in Label Map.\n";
                continue;
            }
            string Data=to_string(classNum)
                    +" "+to_string(normCenter(dataList[i][4],dataList[i][6],dataList[i][1]))
                    +" "+to_string(normCenter(dataList[i][5],dataList[i][7],dataList[i][2]))
                    +" "+to_string(normLength(dataList[i][4],dataList[i][6],dataList[i][1]))
                    +" "+to_string(normLength(dataList[i][5],dataList[i][7],dataList[i][2]));
            writeData(filename,Data);
            std::cout<<std::endl;
        }
    }
}
void toyoloconvert::convertObjs(string newImgDir){
    int skippedBySize=0;
    for(size_t j=0;j<this->labelsAddr.size();j++)
    {
    CSVReader reader(labelsAddr[j]);
        // Get the data from CSV File
        std::cout<<"Label Address Loaded: "<<labelsAddr[j]<<"\n";
	std::vector<std::vector<std::string> > dataList = reader.getData();
        // Print the content of row by row on screen
	std::cout<<"Loaded Files: "<<dataList.size()<<std::endl;
        for(size_t i=1;i<dataList.size();i++)
//        for(std::vector<std::string> vec : dataList)
        {
            int obj_num=0;
            string filename_txt; // without format .txt or .jpg
            std::string token;
            std::string token_plus_num;
            // Print File Name:
            cout<<dataList[i][0]<<std::endl;
//std::cout<<"60\n";
bool existBefore=false;
std::vector<std::vector<std::string>> dataStorage;
            do {
    if(!existBefore)
        existBefore=true;
    else{
        dataStorage.push_back(dataList[i-obj_num]);
    }
                token = dataList[i][0].substr(0, dataList[i][0].find("."));
                token_plus_num=token+to_format(obj_num++);
                filename_txt=labelDir+"/"+token_plus_num+".txt";
            } while(boost::filesystem::exists(filename_txt));
            std::cout<<"(66) FileName from Object: "<<filename_txt<<"\n";
            string mainfile_jpg=imgsDir+"/"+token+".jpg";
            if(!boost::filesystem::exists(mainfile_jpg)){
                cout<<"Jpg File doesn't exist.\n";
                continue;
            }
            string filename_jpg=newImgDir+"/"+token_plus_num+".jpg";

            cv::Mat img=cv::imread(mainfile_jpg);
            if(img.empty()){
                cout<<"Jpg File is EMPTY.\n";
                continue;
            }
            int classNum=labeltoNum(dataList[i][3]);
            if(classNum==-1){
                cout<<"Error in Label Map.\n";
                continue;
            }

            // set RoI around Plate:
            cv::Rect roi;
//std::cout<<"78\n";
            //width=xmax-xmin
            int width=stoi(dataList[i][6])-stoi(dataList[i][4]);
            if(width<stoi(dataList[i][1])/25){
                skippedBySize++;
                continue;
            }
            int height=stoi(dataList[i][7])-stoi(dataList[i][5]);
//std::cout<<"82\n";
            int num_of_margin=1+(rand()%3);
            //set Random Margin Seed
            int n_w=rand()%(static_cast<int>(num_of_margin*width));
//std::cout<<"Random width margin: "<<n_w<<std::endl;
int n_h;
if(this->rect){
n_h=rand()%(static_cast<int>(num_of_margin*height));
}
else{
   n_h=rand()%(static_cast<int>(num_of_margin*width));
   height=width;
}
//std::cout<<"Random height margin: "<<n_h<<std::endl;
            int min_pad=rand()%10;
            //x=xmin y=ymin
//std::cout<<"90\n";
            while ((stoi(dataList[i][4])-n_w)<0) {
//std::cout<<"roi.x out of range!\n";
                n_w--;
            }
//std::cout<<"94\n";
            int roi_x=(stoi(dataList[i][4])-n_w);
            while ((stoi(dataList[i][5])-n_h)<0) {
//std::cout<<"roi.y out of range!\n";
                n_h--;
            }
            int roi_y=(stoi(dataList[i][5])-n_h);
            int mulNum=2*num_of_margin+1;
//std::cout<<"100\n";
            int margin_w=0;
            int margin_h=0;
            bool changedMulWidth=false;
            while((roi_x+width*mulNum+margin_w)>stoi(dataList[i][1])){
                margin_w--;
                changedMulWidth=true;
            }
            int roi_width=width*mulNum+margin_w;
            if(changedMulWidth){
                mulNum=((width*mulNum+margin_w)/width)+0.5;
                roi_y+=n_h/mulNum;
            }
            while((roi_y+height*mulNum+margin_h)>stoi(dataList[i][2])){
                margin_h--;
            }
//std::cout<<"107\n";
            roi.x=roi_x;
            roi.y=roi_y;
            roi.width=roi_width;
            int roi_height=height*mulNum+margin_h;
            if(roi_height<roi_width/2){
                skippedBySize++;
                continue;
            }
            roi.height=roi_height;
            std::cout<<"RoI(x,y) : ("<<roi_x<<","<<roi_y<<") - (w,h) : ("<<roi_width<<","<<roi_height<<")\n";
            cv::Mat objCroped=img(roi);
            cv::imwrite(filename_jpg,objCroped);
            string Data=to_string(classNum)
                    +" "+to_string(normCenter(dataList[i][4],dataList[i][6],roi_x,objCroped.size().width))
                    +" "+to_string(normCenter(dataList[i][5],dataList[i][7],roi_y,objCroped.size().height))
                    +" "+to_string(normLength(dataList[i][4],dataList[i][6],objCroped.size().width))
                    +" "+to_string(normLength(dataList[i][5],dataList[i][7],objCroped.size().height));
            writeData(filename_txt,Data);
            for(size_t i=0;i<dataStorage.size();i++){
                if((roi.contains(cv::Point(stoi(dataStorage[i][4]),stoi(dataStorage[i][5]))))
                        ||(roi.contains(cv::Point(stoi(dataStorage[i][6]),stoi(dataStorage[i][7]))))){
                    // in roi
                    string Data;
                    if((roi.contains(cv::Point(stoi(dataStorage[i][4]),stoi(dataStorage[i][5]))))
                            &&(roi.contains(cv::Point(stoi(dataStorage[i][6]),stoi(dataStorage[i][7]))))){
                        Data=to_string(labeltoNum(dataStorage[i][3]))
                                +" "+to_string(normCenter(dataStorage[i][4],dataStorage[i][6],roi_x,objCroped.size().width))
                                +" "+to_string(normCenter(dataStorage[i][5],dataStorage[i][7],roi_y,objCroped.size().height))
                                +" "+to_string(normLength(dataStorage[i][4],dataStorage[i][6],objCroped.size().width))
                                +" "+to_string(normLength(dataStorage[i][5],dataStorage[i][7],objCroped.size().height))
                                                                ;
//                                +"| x-min,-max roi-x,-y roi-w,roi-h y-min,-max ds(4-7) :"
//                                +dataStorage[i][4]+","+dataStorage[i][5]+","+dataStorage[i][6]+","+dataStorage[i][7];
                    }
                    else {
                        int x_min=(stoi(dataStorage[i][4])>=roi_x)?stoi(dataStorage[i][4]):roi_x;
                        int y_min=(stoi(dataStorage[i][5])>=roi_y)?stoi(dataStorage[i][5]):roi_y;
                        int x_max=(roi_x+roi_width>=stoi(dataStorage[i][6]))?stoi(dataStorage[i][6]):(roi_x+roi_width);
                        int y_max=(roi_y+roi_height>=stoi(dataStorage[i][7]))?stoi(dataStorage[i][7]):(roi_y+roi_height);
                        Data=to_string(1)
                                +" "+to_string(normCenter(x_min,x_max,roi_x,objCroped.size().width))
                                +" "+to_string(normCenter(y_min,y_max,roi_y,objCroped.size().height))
                                +" "+to_string(normLength(x_min,x_max,objCroped.size().width))
                                +" "+to_string(normLength(y_min,y_max,objCroped.size().height))
                                ;
                    }
                    writeData(filename_txt,Data);
                }
                else
                    continue;
            }
            std::cout<<"Label "<<j+1<<" from "<<this->labelsAddr.size()<<" - "<<"file "<<i+1<<" from "<<dataList.size()<<std::endl;
        }
    }
    cout<<"\nSkipped Obj cause width-Size less than 4% :"<<skippedBySize<<endl;

}
void toyoloconvert::writeData(string &filename, string Data){
    std::ofstream outfile;

    outfile.open(filename, std::ios_base::app);
    outfile <<Data<<endl;
    outfile.close();
}
int toyoloconvert::labeltoNum(string label){
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
double toyoloconvert::normCenter(string min, string max,string size){
//    cout<<"min"<<stoi(min)<<endl;
//    cout<<"max"<<stoi(max)<<endl;
//    cout<<"median"<<(stoi(min)+stoi(max))/2<<endl;
    double c=static_cast<float>(((stoi(min)+stoi(max))/2))/static_cast<float>(stoi(size));
    return c;
}
double toyoloconvert::normCenter(string min, string max,int xy,int wh){
    double c=static_cast<float>(static_cast<float>(((stoi(min)+stoi(max))/2))-xy)/static_cast<float>(wh);
    return c;
}
double toyoloconvert::normCenter(int min, int max,int xy,int wh){
    double c=static_cast<float>(static_cast<float>(((min+max)/2))-xy)/static_cast<float>(wh);
    return c;
}
double toyoloconvert::normLength(string min, string max, string size){
    double c=(static_cast<float>(stoi(max)-stoi(min))/static_cast<float>(stoi(size)));
    return c;
}
double toyoloconvert::normLength(string min, string max, int size){
    double c=(static_cast<float>(stoi(max)-stoi(min))/static_cast<float>(size));
    return c;
}
double toyoloconvert::normLength(int min, int max, int size){
    double c=(static_cast<float>(max-min)/static_cast<float>(size));
    return c;
}
