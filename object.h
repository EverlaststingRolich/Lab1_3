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
   int get_volume() const;
   int get_price() const;

   virtual int get_data(const string& type) const;

    void set_name(string value);
    void set_volume(int value);
    void set_price(int value);




private:
    string name;
    int volume;
    int price;
};

#endif // OBJECT_H
