#ifndef PLATECROP_H
#define PLATECROP_H

#include "definition.h"
#include <csvreader.h>

class platecrop
{
public:
    platecrop();
    int init(string labelfile,string imgsDir,string labelDir,string cropImgDir, string labelMap,int method);
    int run();
private:
    int labeltoNum(string label);
    string labelfile;
    string labelDir;
    string imgsDir;
    string cropImgDir;
    string labelMap;
    int method;
    void writeData(string &filename,string Data);

    std::string to_format(const int number) {
        std::stringstream ss;
        ss << std::setw(2) << std::setfill('0') << number;
        return ss.str();
    }
};

#endif // PLATECROP_H
