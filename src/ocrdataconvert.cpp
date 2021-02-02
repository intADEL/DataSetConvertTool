#include "ocrdataconvert.h"

OCRDataConvert::OCRDataConvert()
{

}
int OCRDataConvert::init(string rawImgDir, string LabelDir, string AlphabetMap, int Method){
    this->rawImgDir=rawImgDir;
    this->LabelDir=LabelDir;
    this->AlphabetMap=AlphabetMap;
    this->Method=Method;
}


int OCRDataConvert::run(){

}
int OCRDataConvert::RunMethod1(){
    string fileName, labelNum;
    for (const auto & file : directory_iterator(this->rawImgDir)){
        boost::this_thread::sleep_for(boost::chrono::milliseconds(100));
        char sep='/';
        fileName=getFileName(file.path().string(),sep);
        sep='_';
        labelNum=getFileName(fileName,sep);

        boost::this_thread::sleep_for(boost::chrono::milliseconds(100));
    }
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
