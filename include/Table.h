#include "Row.h"
#ifndef Table_h
#define Table_h

class Table
{
private:
    std::vector<Row> rows;
public:
    Table() = default;
    ~Table();
    Table(const Table &table);

    friend std::ostream& operator <<(std::ostream &out, const Table &table);

    void addRow(std::vector<std::string> row);
    void Sort(int column1, int column2);
    int NumOfColumns();
};


#endif