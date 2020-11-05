#include <iostream>
#include <object.h>
#include <assert.h>
#include <string>
#include <object_collection.h>

using namespace std;

int to_screen(object_collection other) // Вывод на экран
{
    for (int i = 1; i < int(other.get_size()+1); i++)
    {
        other.set_iterator_index(i);
        cout << i << ") Name: " << other.get_iterator_value().get_name() << " Volume: " << other.get_iterator_value().get_volume() << " Price: " << other.get_iterator_value().get_price() << endl;
    }
    cout << "\n" << endl;
    return 0;
}

void test_collection_class()
{
    // Тесты коллекции
    object object2("phone", 5, 1000 );
    assert(object2.get_name() == "phone");
    assert(object2.get_volume() == 5);
    assert(object2.get_price() == 1000);

    // Тестирование конструктора по умолчанию
    object_collection def_coll;
    assert(def_coll.get_iterator_index()==0);
    assert(def_coll.get_iterator_value().get_name()=="" && def_coll.get_iterator_value().get_volume()==0 && def_coll.get_iterator_value().get_price()==0);
    assert(def_coll.get_size()==0);

    //Тестирование конструктора коппирования
    object object4("Ipad", 3, 2000);
    def_coll.add_elem(object4, 1);
    object_collection def_copy(def_coll);
    assert(def_copy == def_coll); // Проверка двух коллекций на равенство
    assert(def_copy.get_iterator_value().get_name() == def_coll.get_iterator_value().get_name() &&
           def_copy.get_iterator_value().get_volume() == def_coll.get_iterator_value().get_volume() &&
           def_copy.get_iterator_value().get_price() == def_coll.get_iterator_value().get_price());
    assert(def_copy.get_size() == def_coll.get_size());

    // Тестирование методов удаления и добавления
    object object5("Pen", 5, 40);
    def_coll.add_elem(object5, 2);
   // assert(def_coll.get_iterator_value().get_name() == "Pen" && def_coll.get_iterator_value().get_volume() == 5 && def_coll.get_iterator_value().get_price() == 40);
    assert(def_coll.get_size() == 2);
    def_coll.remove(2);
    def_coll.set_iterator_index(1);
    assert(def_coll.get_iterator_value().get_name() == "Ipad" && def_coll.get_iterator_value().get_volume() == 3 && def_coll.get_iterator_value().get_price() == 2000);
    assert(def_coll.get_size() == 1);
    def_coll.add_elem(object2, 1);
    assert(def_coll.get_iterator_value().get_name() == "phone" && def_coll.get_iterator_value().get_volume() == 5 && def_coll.get_iterator_value().get_price() == 1000);
    assert(def_coll.get_size() == 2);
    def_coll.remove(1);
    def_coll.remove(1);
    assert(def_coll.get_size() == 0);

    //Тестирование метода доступа к элементу: вывод на экран всех хранимых объектов
    def_coll.add_elem(object5, 1);
    def_coll.add_elem(object4, 1);
    def_coll.add_elem(object2, 1);
    assert(to_screen(def_coll) == 0);

    // Тестирование метода удаления всех хранимых объектов
    def_coll.clean();
    assert(def_coll.get_size() == 0);

    // Тестирование методов записи в файл и чтение файла
    object object6("calculator", 5, 100);
    object object7("Glasses", 5, 1100);
    object_collection ob_to_file;
    ob_to_file.add_elem(object6, 1);
    ob_to_file.add_elem(object7, 2);
    assert(ob_to_file.to_file("D:\\LAB_PROGRAMMING\\Laba1_-1_OOP-master\\Lab1\\to.txt") == 0);
    object_collection ob_from_file;
    assert(ob_from_file.from_file("D:\\LAB_PROGRAMMING\\Laba1_-1_OOP-master\\Lab1\\to.txt") == 0);
    assert(ob_from_file == ob_to_file); // Проверка на равенство записанной в файл и полученной из файла коллекцией
}
