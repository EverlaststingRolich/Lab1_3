#ifndef MONEY_STACK_H
#define MONEY_STACK_H
#include "object.h"
#include <string.h>

class money_stack : public object
{
    public:
        money_stack();
        money_stack(const string &name, const int &volume, const int &price);
        money_stack(const money_stack &other);
        int get_new_volume() const;
        void set_new_volume(const int& value);
        string get_data(const string &type) const;

    private:
        int new_volume;

};

#endif // MONEY_STACK_H
