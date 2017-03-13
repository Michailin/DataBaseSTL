#include "database.h"
#include <fstream>
#include <string>
#include <sstream>

DataBase::DataBase()
{
}
DataBase::DataBase(const char *pathToFile) throw (DataBaseException)
{
    std :: ifstream input(pathToFile);
    if(!input.is_open())
        throw DataBaseException("cannot open file");
    char delim = ' ';
    std :: string s;
    Register r;
    int counter = 0;
    int userID;
    std :: string item;
    double price;
    char data1[12];
    int j = 0;
    while(input.good())
    {
        std :: getline(input,s);
        std :: stringstream ss(s);
        ss >> userID;
        ss >> item;
        ss >> price;
        ss >> data1;
        r.setUserID(userID);
        r.setItem(item);
        r.setPrice(price);
        r.setData(data1);
        data.push_back(r);
        //sortedByData.push_back(j);
        //sortedByID.push_back(j);
        //sortedByItem.push_back(j);
        //sortedByPrice.push_back(j);
        j++;
    }
    std :: sort(sortedByData.begin(),sortedByData.end(),Register :: ComparatorData(&data));
    std :: sort(sortedByItem.begin(),sortedByItem.end(),Register :: ComparatorItem(&data));
    std :: sort(sortedByID.begin(),sortedByID.end(),Register :: ComparatorID(&data));
    std :: sort(sortedByPrice.begin(),sortedByPrice.begin(),Register :: ComparatorPrice(&data));
    for(std :: vector <int> :: iterator it = sortedByID.begin(); it < sortedByID.end();it++)
        data[*it].itID = it;
    for(std :: vector <int>)
}
void DataBase :: printData() const
{
    for(int i = 0; i < data.size(); i++)
        std :: cout <<data[i].getUserID() << " " <<  data[i].getItem() << " " << data[i].getPrice() << " " << data[i].getData() << std :: endl;
}
