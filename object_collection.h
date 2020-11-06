#ifndef OBJECT_COLLECTION_H
#define OBJECT_COLLECTION_H
#include <string>
#include "object.h"
#include "money_stack.h"
using namespace std;

struct lista
{
    object field; //поле данных
    struct lista *next; // указатель на следующий элемент
    struct lista *prev; // указатель на предыдущий элемент
};

class object_collection
{
public:
    object_collection();
    object_collection(const object_collection& other);

    int add_elem(object ob, int number); // Добавление элемента в середину
    int add_head(object ob); // Добавление элемента в начало
    int add_tail(object ob); // Добавление элемента в конец

    int remove(int index); //удаление элемента под заданным номером
    int clean(); // Очистка весго списка

    int get_size();// Получение длины списка

    void set_iterator_index(int index);
    void set_iterator_value(object ob);
    int get_iterator_index();
    object get_iterator_value();



    int from_file(const string &name);
    int to_file(const string &name);

    bool operator == (const object_collection&); // Оператор сравнения


    void sort(); //Сортировка элементов списка по стоимости(при добавлении)

private:
    pair<int,object> iterator;
    lista *list_;
    lista *head, *tail; // начало и конец списка
    int size;
};

#endif // OBJECT_COLLECTION_H
