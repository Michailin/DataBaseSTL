#ifndef DATABASE_H
#define DATABASE_H
#include <vector>
#include <cstring>
#include <algorithm>
#include "register.h"
#include <cstdio>

class DataBaseException
{
public:
    const char * reason;
    DataBaseException():
        reason("default reason")
    {}
    DataBaseException(const char * reason_):
        reason(reason_)
    {}
};
class DataBase
{
private :
    std :: vector <Register> data;
    std :: vector <int> sortedByID;
    std :: vector <int> sortedByItem;
    std :: vector <int> sortedByPrice;
    std :: vector <int> sortedByData;
public:
    DataBase();
    DataBase(const char * pathToFile) throw (DataBaseException);
    DataBase(FILE * file) throw (DataBaseException);

    void getFullRange(std :: vector <Register> & ret,int idBegin,int idEnd,const std :: string & begin,const std :: string & end,double priceBegin,double priceEnd,char * dataBegin,char * dataEnd) const;
    void getIDRange(std :: vector <Register> & ret,int idBegin,int idEnd) const;
    void getItemRange(std :: vector <Register> & ret,const std :: string & begin,const std :: string & end) const;
    void getPriceRange(std :: vector <Register> & ret,double priceBegin,double priceEnd) const;
    void getDataRange(std :: vector <Register> & ret,char dataBegin[12],char dataEnd[12]) const;

    void printData() const;
};

#endif // DATABASE_H
