#ifndef PLATECROP_H
#define PLATECROP_H

#include "definition.h"
#include <csvreader.h>
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
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
        ss << std::setw(4) << std::setfill('0') << number;
        return ss.str();
    }
    std::vector<fs::path> get_all(fs::path const & root, std::string const & ext);
};

#endif // PLATECROP_H
