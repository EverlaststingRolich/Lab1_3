#include "object_collection.h"
#include <iostream>
#include <fstream>
#include <string.h>

object_collection::object_collection()
{
    this->list_ = new lista;
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;

    this->iterator.first = 0;
    this->iterator.second = this->list_->field;
}

object_collection::object_collection(const object_collection& other)
{
    this->head = NULL;
    this->tail = NULL;

    lista *temp = other.head;
    while (temp != 0)
    {
        add_tail(temp->field);
        temp = temp->next;
    }
    this->iterator = other.iterator;
    this->size = other.size;
}

int object_collection::add_elem(object ob, int pos)
{
    if ((ob.get_volume() != 0))
    {
        if (pos == this->size+1)// Добавление в конец списка
        {
            add_tail(ob);
            return 0;
        }
        else if(pos == 1)// Добавление в начало списка
        {
            add_head(ob);
            return 0;
        }
        // Добавление в произвольное место, кроме начала и конца
        int i = 1;
        lista *ins = head;
        while (i<pos)
        {
            ins = ins->next;
            i++;
        }
        lista *prev_ins = ins->prev;
        lista *temp = new lista;
        temp->field = ob;

        if(prev_ins != 0 && this->size != 1)
            prev_ins->next = temp;

        temp->next = ins;
        temp->prev = prev_ins;
        ins->prev = temp;


        iterator.first++;
        this->iterator.second = ob;
        this->size++;
        return 0;
    }
    sort();
    return 1;
}

int object_collection::add_head(object ob)
{
    if ((ob.get_volume() != 0))
    {
        lista *temp = new lista;
        temp->prev = 0;
        temp->field = ob;
        temp->next = head;
        if(head != 0)
            head->prev = temp;
        // Если элемент первый, то он одновремено и голова и хвост
        if(this->size == 0)
            head = tail = temp;
        else
            head = temp; // иначе новый элемент - голова

        iterator.first++;
        this->iterator.second = ob;
        this->size++;
        return 0;
    }
    return 1;
}

int object_collection::add_tail(object ob)
{
    if ((ob.get_volume() != 0))
    {
        lista *temp = new lista;
        temp->next = NULL;
        temp->field = ob;

        if (this->head != NULL)
        {
            temp->prev = this->tail;
            this->tail->next = temp;
            this->tail = temp;
        }
        else
        {
            temp->prev = NULL;
            this->head = this->tail = temp;
        }

        iterator.first++;
        this->iterator.second = ob;
        this->size++;
        return 0;
    }
    return 1;
}

int object_collection::remove(int index)
{
    if ((index == 1) && (this->head->next)) // Если удаляем первый, но есть и другие
    {
        lista *temp = this->head;
        this->head = this->head->next;
        this->head->prev = NULL;
        delete temp;
        this->size--;
        return 0;
    }
    else if ((index ==1) && (this->head == this->tail))
    {
        this->head->next = NULL;
        this->head = NULL;
        delete this->head;
        this->size = 0;
        return 0;
    }

    //Если удаляемый элемент является последним
    if (index==this->size)
    {
        lista *temp = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = NULL;
        delete temp;
        this->size--;
        return 0;
    }

    //Если удаляемый элемент лежит в середине
    lista *temp = this->head, *temp2; // temp - удаляемый элемент, temp2 нужен чтобы не потерять данные
    for (int i=0; i<index-1; i++)
        temp = temp->next;
    temp2 = temp;
    temp2->prev->next = temp->next;
    temp2->next->prev = temp->prev;
    delete temp;

    if (this->iterator.first >= this->size)
        this->iterator.first = this->size-1;
    for (int i=0; i<this->iterator.first-1; i++)
        this->list_ = this->list_->next;
    this->iterator.second = this->list_->field;
    this->size--;
    return 0;
}

int object_collection::clean()
{
    while (this->head)
    {
        this->tail=this->head->next;
        delete this->head;
        this->head=this->tail;
    }
    this->list_ = new lista;
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
    return 0;
}

void object_collection::sort()
{
    int swapped;
    int pr1, vol1, pr2, vol2;
    lista *ptr1;
    lista *lptr = NULL;

    if (this->head == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = this->head;
        while(ptr1->next != lptr)
        {
            pr1 = ptr1->field.get_price();
            pr2 = ptr1->next->field.get_price();
            vol1 = ptr1->field.get_volume();
            vol2 = ptr1->next->field.get_volume();

            if(pr1/vol1 > pr2/vol2)
            {
                swap(ptr1->field, ptr1->next->field);
                swapped = 1;
            }
           ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while(swapped);
}

int object_collection::get_size()
{
    return this->size;
}

void object_collection::set_iterator_index(int index)
{
    if (this->iterator.first != index && index < this->size+1 && index >= 0)
    {
        this->iterator.first = index;
        int i=0;
        lista *temp = head;
        while(i != index-1)
        {
            temp = temp->next;
            i++;
        }
        this->iterator.second = temp->field;
    }
}

void object_collection::set_iterator_value(object ob)
{
    if (ob.get_volume() > 0)
    {
        int i = 0;
        lista *temp = head;
        while (i != get_iterator_index()-1)
        {
            temp = temp->next;
            i++;
        }
        temp->field = ob;
        this->iterator.second = ob;
    }
}

int object_collection::get_iterator_index()
{
    return this->iterator.first;
}


object object_collection::get_iterator_value()
{
    return this->iterator.second;
}




int object_collection::from_file(const string &fname)
{
    string name;
    int volume;
    int price;
    ifstream file(fname);

    if(this->size>0)
    {
        this->clean();
        this->iterator.first = 0;
    }

    if (file.is_open())
    {
        while(file >> name >> volume >> price)
        {
            object ob (name, volume, price);
            if ((ob.get_volume()!= 0) && (ob.get_volume()>0) && (ob.get_price()>=0))
                this->add_tail(ob);
        }
        file.close();
    }
    return 0;
}

int object_collection::to_file(const string &fname)
{
    ofstream fout(fname);

    for (int i = 1; i < int(this->size+1); i++)
    {
        this->set_iterator_index(i);
        fout << this->get_iterator_value().get_name() <<" " << this->get_iterator_value().get_volume() << " " << this->get_iterator_value().get_price() << endl;
    }
    fout.close();
    return 0;
}

bool object_collection::operator==(const object_collection& l)
{
    // Сравнение по количеству
    if(this->size != l.size)
        return false;

    lista *t1, *t2;
    t1 = head;
    t2 = l.head;

    //Сравнение по содержанию
    while(t1 != 0)
    {
        //Сверяем данные, которые находятся на одинаковых позициях
        if (t1->field.get_name() != t2->field.get_name() && t1->field.get_volume() != t2->field.get_volume() && t1->field.get_price() != t2->field.get_price())
            return false;
        t1 = t1->next;
        t2 = t2->next;
    }
    return true;
}
