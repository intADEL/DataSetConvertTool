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
