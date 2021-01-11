#include <iostream>
#include <fstream>
#include <vector>

#include "../include/CsvSorter.h"

int main(int argc, char **argv)
{
    try {
        std::string file_name = argv[1];

        FileReader *fr;

        // .csv file extension
        if(file_name.substr(file_name.find_last_of(".") + 1) == "csv")
        {
            fr = new CsvSorter();
        }

        fr->read(file_name);

        std::vector<std::string> arguments;
        for(int i=2; i<argc; i++)
        {
            arguments.push_back(argv[i]);
        }
        fr->modify(arguments);

        delete fr;
    }
    catch(...) {
        std::cout << "Enter correct file name along with executable in the command line" << std::endl;
    }

    return 0;
}