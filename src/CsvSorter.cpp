#include "../include/CsvSorter.h"
#include <fstream>
#include <sstream>

// constructor
CsvSorter::CsvSorter():
    table()
{
}
// destructor
CsvSorter::~CsvSorter()
{
}

// copy constructor
CsvSorter::CsvSorter(const CsvSorter &csv)
{
}

// reads contents of the given file
void CsvSorter::read(std::string file_name)
{
    this->file_name = file_name;

    std::ifstream fileStream;
    fileStream.open(file_name);

    while(fileStream.good())
    {
        std::string line;
        getline(fileStream, line, '\n');
        
        std::vector<std::string> row;
        std::istringstream ss(line);
        
        while(ss.good())
        {
            std::string substr;
            getline(ss, substr, ',');
            row.push_back(substr);
        }
        
        // checks if the line has any data
        bool empty_row = true;
        for(int i=0; i<row.size(); i++)
        {
            if(!row[i].empty())
            {
                empty_row = false;
                break;
            }
        }
        if(!empty_row)
            table.addRow(row);
    }
}

void CsvSorter::modify(std::vector<std::string> details)
{
    int column1 = Value(details[0]);
    int column2 = Value(details[1]);
    if(column1<table.NumOfColumns() && column2<table.NumOfColumns())    // checks if the input column number exists in the table
    {
        table.Sort(column1, column2);
        std::ofstream outputStream;
        outputStream.open(file_name.substr(0,file_name.find_last_of('.')) + "_sorted.csv");
        outputStream << table;
    }
    else
        std::cout << "Enter valid columns to sort" << std::endl;
}

int CsvSorter::Value(std::string column)
{
    int base = 1;
    int value = 0;
    for(int i=column.length()-1; i>=0; i--)
    {
        value += (column[i] - 64)*base;
        base *= 26;
    }
    return value-1;
}