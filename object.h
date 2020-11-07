#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>


using namespace std;

class object
{
public:
    object(string name, int volume, int price);
    object(const object& other);
    object();

   const string& get_name() const;
   const int get_volume() const;
   const int get_price() const;

    void set_name(string value);
    void set_volume(int value);
    void set_price(int value);

    virtual int get_new_volume() const;


private:
    string name;
    int volume;
    int price;
};

#endif // OBJECT_H
