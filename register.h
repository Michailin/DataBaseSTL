#ifndef REGISTER_H
#define REGISTER_H
#include <cstring>
#include <iostream>
#include <vector>
class Register
{
private:
    int user_id;
    std :: string item;
    double price;
    char data[12];
public:
    std :: vector <int> :: iterator itID;
    std :: vector <int> :: iterator itItem;
    std :: vector <int> :: iterator itPrice;
    std :: vector <int> :: iterator itData;
public:
    Register():
        user_id(0),
        price(0.0)
    {
        memset(data,9,12);
    }
    Register(const Register & copy):
        user_id(copy.user_id),
        item(copy.item),
        price(copy.price)
    {
        memcpy(data,copy.data,12);
    }
    Register(int user_id_,const std :: string & item_,double price_,const char data_[12]):
        user_id(user_id_),
        item(item_),
        price(price_)
    {
        memcpy(data,data_,12);
    }

    Register & operator = (const Register & copy);

    int getUserID() const;
    std :: string & getItem();
    const std :: string & getItem() const;
    double getPrice() const;
    char * getData();
    const char * getData() const;

    void setUserID(int user_id_);
    void setItem(const std :: string & item_);
    void setPrice(double price_);
    void setData(const char data_[12]);

    class ComparatorID
    {
    private:
        const std :: vector <Register> * data;
    public:
        ComparatorID(const std :: vector <Register> * data_):
            data(data_)
        {}
        bool operator () (int i1, int i2) const;
    };
    class ComparatorItem
    {
    private:
        const std :: vector <Register> * data;
    public:
        ComparatorItem(const std :: vector <Register> * data_):
            data(data_)
        {}
        bool operator () (int i1, int i2) const;
    };
    class ComparatorPrice
    {
    private:
        const std :: vector <Register> * data;
    public:
        ComparatorPrice(const std :: vector <Register> * data_):
            data(data_)
        {}
        bool operator () (int i1,int i2) const;
    };
    class ComparatorData
    {
    private:
        const std :: vector <Register> * data;
    public:
        ComparatorData(const std :: vector <Register> * data_):
            data(data_)
        {}
        bool operator () (int i1,int i2) const;
    };
};
#endif // REGISTER_H
