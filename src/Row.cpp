#include "../include/Row.h"

// constructor
Row::Row(std::vector<std::string> d):
    data(d)
{}

// destructor
Row::~Row()
{}

// friend function for std::ostream
std::ostream& operator <<(std::ostream &out, const Row &row)
{
    std::vector<std::string>::const_iterator iter;
    for(iter = row.data.begin(); iter != row.data.end()-1; iter++)
    {
        out << (*iter) << ",";
    }
    out << (*iter);
    out << '\n';
    return out;
}

// override < operator for sort
bool operator <(const Row &r1, const Row &r2)
{
    int c1 = r1.column_to_sort.first;
    int c2 = r1.column_to_sort.second;
    try {
        if(r1.data[c1] != r2.data[c1])
        {
            return r1.data[c1] < r2.data[c1];
        }
        else
        {
            return r1.data[c2] < r2.data[c2];
        }
    }
    catch(...) {
        std::cout<< "Invalid columns" << std::endl;
    }
    
}

// override == operator for sort
bool operator ==(const Row &r1, const Row &r2)
{
    try{
        int c1 = r1.column_to_sort.first;
        int c2 = r1.column_to_sort.second;
        return (r1.data[c1] == r2.data[c1] && r1.data[c2] == r2.data[c2]);
    }
    catch(...) {
        std::cout<< "Invalid columns" << std::endl;
    }

}

// sets the columns used for sorting
void Row::setColumnsToSort(int column1, int column2)
{
    column_to_sort.first = column1;
    column_to_sort.second = column2;
}

// returns the number of entries in a row
int Row::Size()
{
    return data.size();
}