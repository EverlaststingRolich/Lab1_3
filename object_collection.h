#ifndef OBJECT_COLLECTION_H
#define OBJECT_COLLECTION_H
#include <string>
#include "object.h"
using namespace std;

class object_collection
{
public:
    object_collection();
    object_collection(const object_collection& other);
    int add_elem(object &ob); // Добавление элемент
    int remove();
    int clean(); // Очистка весго списка
    int get_size();// Получение длины списка

    ~object_collection();
    object** get_iterator() const {return this->field;}


    int input_from_file(const string &name);
    int ms_input_from_file(const string &name);
    int output_to_file(const string &name);
    int ms_output_to_file(const string &name);

private:
    object **field{nullptr}; // начало и конец списка
    int size;
};

#endif // OBJECT_COLLECTION_H
