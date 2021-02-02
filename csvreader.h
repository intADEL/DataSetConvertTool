#ifndef CSVREADER_H
#define CSVREADER_H
#include <definition.h>

class CSVReader
        {
            std::string fileName;
            std::string delimeter;
        public:
            CSVReader(std::string filename, std::string delm = ",") :
                    fileName(filename), delimeter(delm)
            { }
            // Function to fetch data from a CSV File
            std::vector<std::vector<std::string> > getData();
        };

#endif // CSVREADER_H
