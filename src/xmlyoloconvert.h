#ifndef XMLYOLOCONVERT_H
#define XMLYOLOCONVERT_H
#include "definition.h"
using namespace pugi;
#include <csvreader.h>
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

class xmlyoloconvert
{
public:
    xmlyoloconvert();
    void setConfig( string labelDir,string imgsDir, string yoloConvDir,string labelMap);
    void run();
private:
    string imgsDir;
    string labelDir;
    string yoloConvDir;
    string labelMap;
    int labeltoNum(string label);
    void writeData(string &filename, string Data);
    std::vector<fs::path> get_all(fs::path const & root, std::string const & ext);
};

#endif // XMLYOLOCONVERT_H
