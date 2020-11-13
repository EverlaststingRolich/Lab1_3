#include "object.h"
#include <iostream>
#include <string>


using namespace std;

object::object()
{
    this->name = "";
    this->volume = 0;
    this->price = 0;
}

object::object(string name, int volume, int price)
{
    this->name = std::move(name);
    if (volume > 0 && price >=0)
    {
        this->volume = volume;
        this->price = price;
    }
    else
    {
        this->volume = 1;
        this->price = 1;
    }
}

object::object(const object& other)
{
    this->name = other.name;
    this->volume = other.volume;
    this->price = other.price;
}

int object:: nv() const
{
    int amount = 0;
    int value = this->price;
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

const string &object::get_name() const
{
    return this->name;
}

int object::get_volume() const
{
    return this->volume;
}

int object::get_price() const
{
    return this->price;
}


void object::set_name(string value)
{
    this->name = std::move(value);
}

void object::set_volume(int value)
{
    if (value > 0)
        this->volume = value;
    else
        this->volume = 1;
}

void object::set_price(int value)
{
    if (value > 0)
        this->price = value;
    else
        this->price = 0;
}

int object::get_data(const string &type) const
{
    if(type == "volume")
        return get_volume();

    if(type == "price")
        return get_price();

    if(type == "new")
        return nv();
    return 111;
}




