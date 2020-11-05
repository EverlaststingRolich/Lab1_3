#include <assert.h>
#include <iostream>
#include "money_stack.h"

using namespace std;

void test_default_constuctor()
{
    money_stack stack;
    assert(stack.get_name() == "");
    assert(stack.get_new_volume() == 0);
    assert(stack.get_price() == 0);
}

void test_init_constructor()
{
    money_stack stack("stack of money", 10, 231);
    assert(stack.get_name() == "stack of money");
    assert(stack.get_price() == 231);
    assert(stack.get_new_volume() == 6);
}

void test_copy_constructor()
{
    money_stack stack("stack of money", 10, 231);
    money_stack stack2(stack);
    assert(stack2.get_name() == "stack of money");
    assert(stack2.get_price() == 231);
    assert(stack2.get_new_volume() == 6);
}

void test_ms_sets()
{
    //Correct data
    money_stack stack;
    stack.set_name("money");
    stack.set_price(123);
    stack.set_new_volume(10);

    assert(stack.get_name() == "money");
    assert(stack.get_price() == 123);
    assert(stack.get_new_volume() == 10);

    //Wrong data
    stack.set_name("cash");
    stack.set_price(12);
    stack.set_new_volume(-10);

    assert(stack.get_name() == "cash");
    assert(stack.get_price() == 12);
    assert(stack.get_new_volume() == 0);
}


void test_ms_class()
{
    test_default_constuctor();
    test_init_constructor();
    test_copy_constructor();
    test_ms_sets();
}
