#include <iostream>
#include <vector>

#ifndef FileReader_h
#define FileReader_h

class FileReader
{
public:
    FileReader() = default;
    virtual ~FileReader();
    FileReader(const FileReader &fr);

    virtual void read(std::string file_name) =0;                    // reads contents of the given file
    virtual void modify(std::vector<std::string> details) =0;       // modifies contents of the input file and writes to new file  
    // "details" gives the commandline arguments
};

#endif