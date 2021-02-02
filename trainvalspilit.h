#ifndef TRAINVALSPILIT_H
#define TRAINVALSPILIT_H
#include <definition.h>

class trainvalspilit
{
public:
    trainvalspilit();
    void init(string rawImgDir,string rawLabelDir,string DataSpilitedDir,string Percent);
    void spilit();
private:
    string rawImgDir;
    string rawLabelDir;
    string DataSpilitedDir;
    float Percent;
int countFile(string pathdir);
std::vector<string> fileList(string pathdir);
void copyFileinDir(std::vector<string> list,string mainDir,string DirName);
};


#endif // TRAINVALSPILIT_H
