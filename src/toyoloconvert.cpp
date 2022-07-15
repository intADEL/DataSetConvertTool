#include "toyoloconvert.h"
#include <string.h>
toyoloconvert::toyoloconvert()
{

}
void toyoloconvert::setConfig(string labeldir, string imgdir, string labelmap, std::vector<string> labeladdrs){
    cout<<"Set config.\n";
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
        // Data: Label Addr's
        std::vector<std::vector<std::string> > dataList = reader.getData();     
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
                }
            while(boost::filesystem::exists(filename_txt));
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
            int num_of_margin=1+1.5*(rand()%3);
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
            while((roi_y+height*mulNum+margin_h)<stoi(dataList[i][7])){
                roi_y++;
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

void toyoloconvert::convertObjsTxtLabels(string newImgDir){
    cout<<"Convert start.\n";
    int skippedBySize=0;
    for(size_t j=0;j<this->labelsAddr.size();j++)
    {
    CSVReader reader(labelsAddr[j]," ");
        // Get the data from CSV File
//        std::cout<<"Label Address Loaded: "<<labelsAddr[j]<<"\n";
    std::vector<std::vector<std::string> > dataList = reader.getData();
        // Print the content of row by row on screen
//    std::cout<<"Loaded Files: "<<dataList.size()<<std::endl;
        for(size_t i=0;i<dataList.size();i++)
//        for(std::vector<std::string> vec : dataList)
        {
            int obj_num=0;
            string filename_txt; // without format .txt or .jpg
            std::string token;
            std::string token_plus_num;
            // Print File Name:
//            cout<<dataList[i][0]<<std::endl;
            std::cout<<"60\n";
            bool existBefore=false;
            std::vector<std::vector<std::string>> dataStorage;
            do {
                if(!existBefore)
                     existBefore=true;
                else{
                     dataStorage.push_back(dataList[i-obj_num]);
                }
                token = dataList[i][0].substr(0, dataList[i][0].find("."));
                token_plus_num=token+"_2_"+to_format(obj_num++);
                filename_txt=labelDir+"/"+token_plus_num+".txt";
                }
            while(boost::filesystem::exists(filename_txt));
//            std::cout<<"(66) FileName from Object: "<<filename_txt<<"\n";
            string mainfile_jpg=imgsDir+"/"+token+".jpg";
            if(!boost::filesystem::exists(mainfile_jpg)){
                cout<<"Jpg File doesn't exist.\n";
                continue;
            }
            string filename_jpg=newImgDir+"/"+token_plus_num+".jpg";
//if(token!="2019-11-29_16-50-02_172193633_29_L1_I")
//    continue;

            cv::Mat img=cv::imread(mainfile_jpg);
            if(img.empty()){
                cout<<"Jpg File is EMPTY.\n";
                continue;
            }
            int classNum=labeltoNum(dataList[i][1]);
            if(classNum==-1){
                cout<<"Error in Label Map.\n";
                continue;
            }

            // set RoI around Plate:
            cv::Rect roi;
            //std::cout<<"78\n";
            //width=xmax-xmin
            vector<string> vec,vec2;
            string temp=dataList[i][2].substr(1, dataList[i][2].size()-2);
            boost::algorithm::split(vec, temp, boost::is_any_of(","));
//            cout<<"x,y: "<<vec[0]<<","<<vec[1]<<endl;
            temp=dataList[i][4].substr(1, dataList[i][4].size()-2);
            boost::algorithm::split(vec2, temp, boost::is_any_of(","));
//            cout<<"x,y: "<<vec2[0]<<","<<vec2[1]<<endl;

            int width=stoi(vec2[0])-stoi(vec[0]);
            if(width<img.size().width/30){
                skippedBySize++;
                continue;
            }
            int height=stoi(vec2[1])-stoi(vec[1]);
            //std::cout<<"82\n";

            int num_of_margin=1+1.5*(rand()%2);


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
            while ((stoi(vec[0])-n_w)<0) {
//std::cout<<"roi.x out of range!\n";
                n_w--;
            }
//std::cout<<"94\n";
            int roi_x=(stoi(vec[0])-n_w);
            while ((stoi(vec[1])-n_h)<0) {
//std::cout<<"roi.y out of range!\n";
                n_h--;
            }
            int roi_y=(stoi(vec[1])-n_h);
            int mulNum=2*num_of_margin+1;
//std::cout<<"100\n";
            int margin_w=0;
            int margin_h=0;
            bool changedMulWidth=false;
            while((roi_x+width*mulNum+margin_w)>img.size().width){
                margin_w--;
                changedMulWidth=true;
            }
            int roi_width=width*mulNum+margin_w;
            if(changedMulWidth){
                mulNum=((width*mulNum+margin_w)/width)+0.5;
                roi_y+=n_h/mulNum;
            }
            while((roi_y+height*mulNum+margin_h)>img.size().height){
                margin_h--;
            }
            while((roi_y+height*mulNum+margin_h)<stoi(vec2[1])){
                roi_y++;
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
//            std::cout<<"Obj(Data Storage size): "<<dataStorage.size()<<endl;
//            if(dataStorage.size()){
//                for(size_t i=0; i<dataStorage.size();i++){
//                cout<<"Data Storage[0]:"<<dataStorage[i][1]<<endl;
//                }
//            }
            cv::Mat objCroped=img(roi);
            cv::imwrite(filename_jpg,objCroped);
            string Data=to_string(classNum)
                    +" "+to_string(normCenter(vec[0],vec2[0],roi_x,objCroped.size().width))
                    +" "+to_string(normCenter(vec[1],vec2[1],roi_y,objCroped.size().height))
                    +" "+to_string(normLength(vec[0],vec2[0],objCroped.size().width))
                    +" "+to_string(normLength(vec[1],vec2[1],objCroped.size().height));
            writeData(filename_txt,Data);
            for(size_t i=0;i<dataStorage.size();i++){
                vector<string> vec,vec2;
                string temp=dataStorage[i][2].substr(1, dataStorage[i][2].size()-2);
                boost::algorithm::split(vec, temp, boost::is_any_of(","));
                temp=dataStorage[i][4].substr(1, dataStorage[i][4].size()-2);
                boost::algorithm::split(vec2, temp, boost::is_any_of(","));
                cout<<"Data stoirage (x,y): "<<vec[0]<<","<<vec[1]<<","<<vec2[0]<<','<<vec2[1]<<endl;
                if((roi.contains(cv::Point(stoi(vec[0]),stoi(vec[1]))))
                        ||(roi.contains(cv::Point(stoi(vec2[0]),stoi(vec2[1]))))){
                    // in roi
                    string Data;
                    if((roi.contains(cv::Point(stoi(vec[0]),stoi(vec[1]))))
                            &&(roi.contains(cv::Point(stoi(vec2[0]),stoi(vec2[1]))))){
                        Data=to_string(labeltoNum(dataStorage[i][1]))
                                +" "+to_string(normCenter(vec[0],vec2[0],roi_x,objCroped.size().width))
                                +" "+to_string(normCenter(vec[1],vec2[1],roi_y,objCroped.size().height))
                                +" "+to_string(normLength(vec[0],vec2[0],objCroped.size().width))
                                +" "+to_string(normLength(vec[1],vec2[1],objCroped.size().height))
                                                                ;
//                                +"| x-min,-max roi-x,-y roi-w,roi-h y-min,-max ds(4-7) :"
//                                +dataStorage[i][4]+","+dataStorage[i][5]+","+dataStorage[i][6]+","+dataStorage[i][7];
                    }
                    else {
                        int x_min=(stoi(vec[0])>=roi_x)?stoi(vec[0]):roi_x;
                        int y_min=(stoi(vec[1])>=roi_y)?stoi(vec[1]):roi_y;
                        int x_max=(roi_x+roi_width>=stoi(vec2[0]))?stoi(vec2[0]):(roi_x+roi_width);
                        int y_max=(roi_y+roi_height>=stoi(vec2[1]))?stoi(vec2[1]):(roi_y+roi_height);
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
void toyoloconvert::convertObjsYoloLabels(string newImgDir,string newLabelDir){
    int lut[6]={0,1,2,3,4,5};

    int skippedBySize=0;
    path p(this->labelDir);
    if(is_directory(p)) {
        std::cout << p << " is a directory containing:\n";
        string Data,token_plus_num;
        vector<string> vec;
        for(auto& entry : boost::make_iterator_range(directory_iterator(p), {}))
        {
            boost::this_thread::sleep_for(boost::chrono::milliseconds(20));
            std::vector<string> pathVec;
            boost::algorithm::split(pathVec, entry.path().string(), boost::is_any_of("/"));
            cout<<"txt file: "<<entry.path().string()<<endl;
            boost::algorithm::split(vec, pathVec.back(), boost::is_any_of("."));
            string imgAddr=this->imgsDir+"/"+vec[0]+".jpg";
            CSVReader reader(this->labelDir+"/"+vec[0]+".txt"," ");
            // Get the data from TXT File
//            std::cout <<this->labelDir+"/"+vec[0]+".txt" << "\n";
            std::vector<std::vector<std::string> > dataList = reader.getData();
                // Print the content of row by row on screen
            cout<<"Reading Label\n";
                for(size_t i=0;i<dataList.size();i++)
                {
                    int obj_num=0;
                    string filename_txt; // without format .txt or .jpg
                    std::string token;
                    std::string token_plus_num;
                    bool existBefore=false;
                    std::vector<std::vector<std::string>> dataStorage;
                    do {
                        cout<<"Generate excited File: i: "<<i<<" obj_num: "<<obj_num<<"\n";
                        if(!existBefore)
                             existBefore=true;
                        else{
                             dataStorage.push_back(dataList[i-obj_num]);
                        }
                        token_plus_num=vec[0]+"_1_"+to_format(obj_num++);
                        filename_txt=newLabelDir+"/"+token_plus_num+".txt";
                        }
                    while(boost::filesystem::exists(filename_txt));
                    std::cout<<"(66) FileName from Object: "<<filename_txt<<"\n";
                    string mainfile_jpg=imgAddr;
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
                    // set RoI around Plate:
                    cv::Rect roi;
                    //width=xmax-xmin
//                    vector<string> vec[2],vec2[2];
                    double width=stod(dataList[i][3])*img.size().width;
                    if(width<10){
                        skippedBySize++;
                        continue;
                    }
                    double height=stod(dataList[i][4])*img.size().height;
                    //std::cout<<"82\n";
                    int num_of_margin=1+1.5*(rand()%2);
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
//                    std::cout<<"Random height margin: "<<n_h<<std::endl;
                    int min_pad=1+(rand()%7);
                    //x=xmin y=ymin
                    //std::cout<<"90\n";
                    double xPt=(stod(dataList[i][1])-stod(dataList[i][3])/2)*img.size().width;
                    double yPt=(stod(dataList[i][2])-stod(dataList[i][4])/2)*img.size().height;
                    double xPt2=(stod(dataList[i][1])+stod(dataList[i][3])/2)*img.size().width;
                    double yPt2=(stod(dataList[i][2])+stod(dataList[i][4])/2)*img.size().height;
//                    cout<<"D :"<<dataList[i][2]<<"-"<<xPt<<endl;

                    while ((xPt-n_w)<0) {
                        n_w--;
                    }
//        std::cout<<"94\n";
                    int roi_x=(xPt-n_w);
                    while ((yPt-n_h)<0) {
        //std::cout<<"roi.y out of range!\n";
                        n_h--;
                    }
                    int roi_y=(yPt-n_h);
                    int mulNum=2*num_of_margin+1;
//        std::cout<<"100\n";
                    int margin_w=0;
                    int margin_h=0;
                    bool changedMulWidth=false;
                    while((roi_x+width*mulNum+margin_w)>img.size().width){
                        margin_w--;
                        changedMulWidth=true;
                    }
                    int roi_width=width*mulNum+margin_w;
                    if(changedMulWidth){
                        mulNum=((width*mulNum+margin_w)/width)+0.5;
                        roi_y+=n_h/mulNum;
                    }
                    while((roi_y+height*mulNum+margin_h)>img.size().height){
                        margin_h--;
                    }
                    while((roi_y+height*mulNum+margin_h)<yPt2){
                        roi_y++;
                    }
//        std::cout<<"107\n";
                    roi.x=roi_x;
                    roi.y=roi_y;
                    roi.width=roi_width;
                    int roi_height=height*mulNum+margin_h;
                    if(roi_height<roi_width/3){
                        skippedBySize++;
                        continue;
                    }
                    roi.height=roi_height;
                    std::cout<<"RoI(x,y) : ("<<roi_x<<","<<roi_y<<") - (w,h) : ("<<roi_width<<","<<roi_height<<")\n";
                    std::cout<<"Obj(Data Storage size): "<<dataStorage.size()<<endl;
        //            if(dataStorage.size()){
        //                for(size_t i=0; i<dataStorage.size();i++){
        //                cout<<"Data Storage[0]:"<<dataStorage[i][1]<<endl;
        //                }
        //            }
                    cv::Mat objCroped=img(roi);
                    cv::imwrite(filename_jpg,objCroped);
//                    string label=(dataList[i][0]==to_string(5))?to_string(1):to_string(0);
                    string label=to_string(lut[stoi(dataList[i][0])]);

                    string Data=label
                            +" "+to_string(normCenter(xPt,xPt2,roi_x,objCroped.size().width))
                            +" "+to_string(normCenter(yPt,yPt2,roi_y,objCroped.size().height))
                            +" "+to_string(normLength(xPt,xPt2,objCroped.size().width))
                            +" "+to_string(normLength(yPt,yPt2,objCroped.size().height));
//                    cout<<"568\n";
                    writeData(filename_txt,Data);
                    for(size_t i=0;i<dataStorage.size();i++){
//                        vector<string> vec,vec2;
//                        string temp=dataStorage[i][2].substr(1, dataStorage[i][2].size()-2);
//                        boost::algorithm::split(vec, temp, boost::is_any_of(","));
//                        temp=dataStorage[i][4].substr(1, dataStorage[i][4].size()-2);
//                        boost::algorithm::split(vec2, temp, boost::is_any_of(","));
//                        cout<<"Data stoirage (x,y): "<<vec[0]<<","<<vec[1]<<","<<vec2[0]<<','<<vec2[1]<<endl;
                        double xPt=(stod(dataStorage[i][1])-stod(dataStorage[i][3])/2)*img.size().width;
                        double yPt=(stod(dataStorage[i][2])-stod(dataStorage[i][4])/2)*img.size().height;
                        double xPt2=(stod(dataStorage[i][1])+stod(dataStorage[i][3])/2)*img.size().width;
                        double yPt2=(stod(dataStorage[i][2])+stod(dataStorage[i][4])/2)*img.size().height;
                        if((roi.contains(cv::Point(xPt,yPt)))
                                ||(roi.contains(cv::Point(xPt2,yPt2)))){
                            // in roi
                            cout<<"in roi\n";
                            string Data;
                            if((roi.contains(cv::Point(xPt,yPt)))
                                    &&(roi.contains(cv::Point(xPt2,yPt2)))){
                                string label=to_string(lut[stoi(dataList[i][0])]);
                                Data=label
                                        +" "+to_string(normCenter(xPt,xPt2,roi_x,objCroped.size().width))
                                        +" "+to_string(normCenter(yPt,yPt2,roi_y,objCroped.size().height))
                                        +" "+to_string(normLength(xPt,xPt2,objCroped.size().width))
                                        +" "+to_string(normLength(yPt,yPt2,objCroped.size().height))
                                                                        ;
                            }
                            else {
                                cout<<"semi in roi 601\n";
                                int x_min=(xPt>=roi_x)?xPt:roi_x;
                                int y_min=(yPt>=roi_y)?yPt:roi_y;
                                int x_max=(roi_x+roi_width>=xPt2)?xPt2:(roi_x+roi_width);
                                int y_max=(roi_y+roi_height>=yPt2)?yPt2:(roi_y+roi_height);
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
                    std::cout<<"file "<<i+1<<" from "<<dataList.size()<<std::endl;
                }

//            writeData(txtAddr,Data);

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
