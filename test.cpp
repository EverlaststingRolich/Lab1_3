#include <iostream>
#include <object.h>
#include <assert.h>

using namespace std;

void test_class()
{
    // Тесты класса
    // По умолчанию
    object object1;
    assert(object1.get_name() == "");
    assert(object1.get_volume() == 0);
    assert(object1.get_price() == 0);

    // Инициализация
    object object2("phone", 5, 1000 );
    assert(object2.get_name() == "phone");
    assert(object2.get_volume() == 5);
    assert(object2.get_price() == 1000);

    //Копирование
    object object3(object2);
    assert(object3.get_name() == object2.get_name());
    assert(object3.get_volume() == object2.get_volume());
    assert(object3.get_price() == object2.get_price());


    // Инициализация с неправильными данными
    object object3_2("book", -5, -200 );
    assert(object3_2.get_name() == "book");
    assert(object3_2.get_volume() >= 0);
    assert(object3_2.get_price() >= 0);

    //Сеттеры и геттеры
    assert(object3.get_name() == "phone");
    assert(object3.get_volume() == 5);
    assert(object3.get_price() == 1000);

    object3.set_name("mobile phone");
    object3.set_volume(2);
    object3.set_price(1500);

    assert(object3.get_name() == "mobile phone");
    assert(object3.get_volume() == 2);
    assert(object3.get_price() == 1500);

    // Сеттер с неправильным значением
    object3.set_name("knife");
    object3.set_volume(-1);
    object3.set_price(-100);

    assert(object3.get_name() == "knife");
    assert(object3.get_volume() == 1);
    assert(object3.get_price() == 0);
}
