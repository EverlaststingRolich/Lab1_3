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
    return 111;
}




