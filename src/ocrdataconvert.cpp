#include "ocrdataconvert.h"

OCRDataConvert::OCRDataConvert()
{

}
int OCRDataConvert::init(string ImgDir,string LabelDirName,int MethodNum){
    this->rawImgDir=ImgDir;
    this->LabelDir=LabelDirName;
    this->AlphabetMap=AlphabetMap;
    this->Method=MethodNum;
}


int OCRDataConvert::run(){
    switch (this->Method) {
    case 1:
        this->RunMethod1();

    }
}
int OCRDataConvert::RunMethod1(){
    string fileName, labelNum;
    std::ofstream outfile;

    int i=0;
    for (const auto & file : directory_iterator(this->rawImgDir)){
        boost::this_thread::sleep_for(boost::chrono::milliseconds(20));
        char sep='/';
        fileName=getFileName(file.path().string(),sep);
        sep='_';
        labelNum=getFileName(fileName,sep);
        labelNum = labelNum.substr(0, labelNum.find("."));

        if(i%20000==0){
            string labelFileAddr=this->LabelDir+"/infofile"+to_format(static_cast<int>(i/20000))+".txt";
            outfile.open(labelFileAddr, std::ios_base::app|ios_base::out);
            boost::this_thread::sleep_for(boost::chrono::milliseconds(25));
            std::cout<<"\nFile: "<<labelFileAddr<<" Created.\n";
        }
        string Data=fileName+"\t"+labelNum;
        outfile <<Data<<endl;
        boost::this_thread::sleep_for(boost::chrono::milliseconds(20));
        i++;
    }
    outfile.close();

}
string OCRDataConvert::getFileName(const string& s,char &sep){
//       char sep = '/';
       string path=s;
       size_t i = path.rfind(sep, path.length());
       if (i != string::npos) {
          return(path.substr(i+1, path.length() - i));
       }
       return("");
    }
int OCRDataConvert::countfile(string pathdir){
        path the_path( pathdir );
        int cnt = std::count_if(
            directory_iterator(the_path),
            directory_iterator(),
            static_cast<bool(*)(const path&)>(is_regular_file) );
        return cnt;
}
