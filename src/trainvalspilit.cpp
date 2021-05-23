#include "trainvalspilit.h"
#include <definition.h>
trainvalspilit::trainvalspilit()
{

}
void trainvalspilit::init(string rawImgDir, string rawLabelDir, string DataSpilitedDir, string Percent){
    this->rawImgDir=rawImgDir;
    this->rawLabelDir=rawLabelDir;
    this->DataSpilitedDir=DataSpilitedDir;
    this->Percent=stof(Percent);
}
void trainvalspilit::spilit(){
    int number_of_files=countFile(this->rawLabelDir);
//    rand()%(number_of_files + 1);
    cout<<"\nNum Of Files:"<<number_of_files<<endl;
    int trainNum=floor(number_of_files*this->Percent);
    cout<<"\ntrainNum:"<<trainNum<<endl;
    std::vector<string> trainAddr;
    std::vector<string> valAddr;
    std::vector<string> filelist=fileList(this->rawLabelDir);
    while(trainAddr.size()<trainNum){
        int n=rand()%filelist.size();
        trainAddr.push_back(filelist[n]);
        filelist.erase(filelist.begin()+n);
    }
    cout<<"\ntrain Num:"<<trainAddr.size()<<endl;
    cout<<"\nval Num:"<<filelist.size()<<endl;

//    cout<<"\ntrain(0):"<<token<<endl;
//    cout<<"\nvalidation(0):"<<filelist[0]<<endl;

copyFileinDir(trainAddr,this->DataSpilitedDir,"train");
copyFileinDir(filelist,this->DataSpilitedDir,"val");

}
int trainvalspilit::countFile(string pathdir){
    path the_path( pathdir );


    int cnt = std::count_if(
        directory_iterator(the_path),
        directory_iterator(),
        static_cast<bool(*)(const path&)>(is_regular_file) );
    return cnt;
}
std::vector<string> trainvalspilit::fileList(string pathdir){
    std::vector<string> filelist;
    for (const auto & file : directory_iterator(pathdir)){
        boost::this_thread::sleep_for(boost::chrono::milliseconds(100));
        filelist.push_back(file.path().string());
        boost::this_thread::sleep_for(boost::chrono::milliseconds(100));
    }
    return  filelist;
}
void trainvalspilit::copyFileinDir(std::vector<string> list, string mainDir, string DirName){
    cout<<"Coppying "<<DirName<<" files.\n";
    for(int i=0;i<list.size();i++){
        if(list[i].empty())
            continue;
        std::string token = list[i].substr(list[i].find_last_of("/")+1);
        std::string filename = token.substr(0, token.find("."));
        std::string writtingAddr=mainDir+"/labels/"+DirName+"/"+filename+".txt";
        copy_file(list[i],writtingAddr,copy_option::overwrite_if_exists);
        std::string imgSrcAddr=this->rawImgDir+"/"+filename+".jpg";
        std::string imgDestAddr=mainDir+"/images/"+DirName+"/"+filename+".jpg";
        if(boost::filesystem::exists(imgSrcAddr)){
        copy_file(imgSrcAddr,imgDestAddr,copy_option::overwrite_if_exists);
        cout<<"\t copying "<<i+1<<" of "<<list.size()<<" - file:"<<imgDestAddr<<" FOUND."<<endl;
        }
        else{
            cout<<"\t copying "<<i+1<<" of "<<list.size()<<" - file:"<<imgDestAddr<<"-NOT Found!"<<endl;
        }
    }
}
