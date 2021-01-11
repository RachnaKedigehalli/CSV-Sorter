#include <iostream>
#include <vector>

#ifndef Row_h
#define Row_h

class Row
{
private:
    std::vector<std::string> data;
    std::pair<int, int> column_to_sort;
public:
    Row() = default;
    Row(std::vector<std::string> data);
    ~Row();

    friend std::ostream& operator <<(std::ostream &out, const Row &row);

    friend bool operator <(const Row &r1, const Row &r2);
    friend bool operator ==(const Row &r1, const Row &r2);

    void setColumnsToSort(int column1, int column2);
    int Size();
};



#endif