#include "register.h"
Register & Register :: operator =(const Register & copy)
{
    user_id = copy.user_id;
    item = copy.item;
    price = copy.price;
    memcpy(data,copy.data,12);
}
int Register ::  getUserID()const
{
    return user_id;
}
std :: string & Register :: getItem()
{
    return item;
}
const std :: string & Register :: getItem() const
{
    return item;
}
double Register :: getPrice() const
{
    return price;
}
char * Register :: getData()
{
    return data;
}
const char * Register :: getData() const
{
    return data;
}
void Register :: setUserID(int user_id_)
{
    user_id = user_id_;
}
void Register :: setItem( const std :: string & item_)
{
    item = item_;
}
void Register :: setPrice(double price_)
{
    price = price_;
}
void Register :: setData(const char data_[12])
{
    memcpy(data,data_,12);
}
bool Register :: ComparatorID :: operator ()(int i1,int i2) const
{
    return (*data)[i1].user_id < (*data)[i2].user_id;
}
bool Register ::ComparatorItem :: operator ()(int i1, int i2) const
{
    //std :: cout << i1 << " " << i2 << " " << (*data)[i2].getItem()<< std :: endl;
    //return false;
   unsigned int minLen = ((*data)[i1].item.length() > (*data)[i2].item.length()) ? (*data)[i2].item.length() : (*data)[i1].item.length();
    for(unsigned int i = 0; i < minLen; i++)
    {
        if(((*data)[i1].item)[i] < ((*data)[i2].item)[i])
            return true;
        else if(((*data)[i1].item)[i] > ((*data)[i2].item)[i])
            return false;
    }
   if(((*data)[i1].item).length() < ((*data)[i2].item).length())
       return true;
   else
        return false;
}
bool Register :: ComparatorPrice :: operator ()(int i1, int i2)const
{
    return (*data)[i1].price < (*data)[i2].price;
}
bool Register :: ComparatorData :: operator ()(int i1,int i2) const
{
    return (strcmp((*data)[i1].data,(*data)[i2].data) < 0);
}

