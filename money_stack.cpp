#include "money_stack.h"
#include <ctype.h>
#include <string.h>



int find_new_volume(const int& price)
{
    int amount = 0;
    int value = price;
    amount = amount + value/100;
    value = value % 100;
    amount = amount + value/50;
    value = value % 50;
    amount = amount + value/10;
    value = value % 10;
    amount = amount + value/5;
    value = value % 5;
    amount = amount + value/1;
    value = value % 1;
    return amount;
}


money_stack::money_stack()
{
    this->new_volume = 0;
}


money_stack::money_stack(const string &name, const int &volume, const int &price):object(name, volume, price)
{
    this->new_volume = find_new_volume(price);
}



money_stack::money_stack(const money_stack &other):object(other)
{
    this->new_volume = other.new_volume;
}


int money_stack::get_new_volume() const
{
    return this->new_volume;
}


void money_stack::set_new_volume(const int &value)
{
    if(value >= 0)
        this->new_volume = value;
    else
        this->new_volume = 0;
}



int money_stack::get_data(const string &type) const
{
    if(type == "volume")
    {
      return get_volume();
      if(type == "price")
      {
          return get_price();
          if(type == "new")
         {
              return this->new_volume;
         }
      }

    }
     else
    {
        return 333;
    }
}
