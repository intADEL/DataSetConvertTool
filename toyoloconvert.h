#ifndef TOYOLOCONVERT_H
#define TOYOLOCONVERT_H

#include <csvreader.h>
#include <definition.h>

class toyoloconvert
{
public:
    toyoloconvert();
    void setConfig(string labeldir,string imgdir,string labelmap, std::vector<string> labeladdrs);
    void convert();
    void convertObjs(string newImgDir);
    bool rect=false;
    bool augment=false;


private:
    string labelDir;
    string imgsDir;
    string labelMap;
    std::vector<string> labelsAddr;
    void writeData(string &filename,string Data);
    int labeltoNum(string label);
    double normCenter(string min,string max,string size);
    double normCenter(string min, string max,int xy,int wh);
    double normLength(string min,string max,string size);
    double normLength(string min, string max, int size);
    double normCenter(int min, int max,int xy,int wh);
    double normLength(int min, int max, int size);

    std::string to_format(const int number) {
        std::stringstream ss;
        ss << std::setw(2) << std::setfill('0') << number;
        return ss.str();
    }
};

#endif // TOYOLOCONVERT_H
