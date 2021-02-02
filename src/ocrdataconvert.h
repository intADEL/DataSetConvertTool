#ifndef OCRDATACONVERT_H
#define OCRDATACONVERT_H

#include <definition.h>

class OCRDataConvert
{
public:
    OCRDataConvert();
    int init(string rawImgDir, string LabelDir, string AlphabetMap, int Method);
    int run();
private:
    int RunMethod1();
    string rawImgDir;
    string LabelDir;
    string AlphabetMap;
    int Method;
};

#endif // OCRDATACONVERT_H
