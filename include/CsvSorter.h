#include "FileReader.h"
#include "Table.h"

#ifndef CsvSorter_h
#define CsvSorter_h

class CsvSorter: public FileReader
{
private:
    std::string file_name;
    Table table;
    
    int Value(std::string column);
public:
    CsvSorter();
    ~CsvSorter();
    CsvSorter(const CsvSorter &csv);

    // implementes virtual functions of base class
    void read(std::string file_name);                   // reads contents of the given file
    void modify(std::vector<std::string> details);      // modifies contents of the input file and writes to new file  
    // "details" gives the commandline arguments
};

#endif