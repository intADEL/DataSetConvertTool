#ifndef OCRDATACONVERT_H
#define OCRDATACONVERT_H

#include <definition.h>

class OCRDataConvert
{
public:
    OCRDataConvert();
    int init(string ImgDir,string LabelDirName,int MethodNum);
    int run();
private:
    int RunMethod1();
    string getFileName(const string& s,char &sep);
    string rawImgDir;
    string LabelDir;
    string AlphabetMap;
    int Method;
    int countfile(string pathdir);
    std::string to_format(const int number) {
        std::stringstream ss;
        ss << std::setw(2) << std::setfill('0') << number;
        return ss.str();
    }
};

#endif // OCRDATACONVERT_H
