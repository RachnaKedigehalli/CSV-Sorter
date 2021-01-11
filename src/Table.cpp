#include "../include/Table.h"

#include <algorithm>

// destructor
Table::~Table()
{}

// copy constructor
Table::Table(const Table &table)
{}

// friend function for std::ostream
std::ostream& operator <<(std::ostream &out, const Table &table)
{
    std::vector<Row>::const_iterator iter;
    for(iter = table.rows.begin(); iter != table.rows.end(); iter++)
    {
        out << (*iter);
    }
    return out;
}

// adds a row to the end of the table
void Table::addRow(std::vector<std::string> data)
{
    Row row(data);
    rows.push_back(row);
}

// sorts table in ascending order using two columns
void Table::Sort(int column1, int column2)
{
    std::vector<Row>::iterator iter;
    for(iter = rows.begin(); iter != rows.end(); iter++)
    {
        (*iter).setColumnsToSort(column1, column2);
    }
    std::sort(rows.begin(), rows.end());
}

// returns the number of columns in the table
int Table::NumOfColumns()
{
    int num = rows[0].Size();
    std::vector<Row>::iterator iter;
    for(iter = rows.begin(); iter != rows.end(); iter++)
    {
        if((*iter).Size() <num) num = (*iter).Size();
    }
    return num;
}