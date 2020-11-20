#include "object_collection.h"
#include "money_stack.h"
#include <iostream>
#include <fstream>
#include <string.h>

object_collection::object_collection()
{
    this->field = nullptr;
    this->size = 0;
}

object_collection::object_collection(const object_collection& other)
{

    if(other.field)
    {
        this->field = new object*[other.size];
        this->size = other.size;
        for(int i = 0; i < this->size; i++)
            this->field[i] = other.field[i];
    }
    else
    {
        this->field = nullptr;
        this->size = 0;
    }

}


int object_collection::add_elem(object &ob)
{
    if (this->field && this->get_size() != 0)
        {
            if ((ob.get_volume() != 0))
            {
                this->size++;
                object **pc = new object*[this->size];
                for(int i = 0; i < this->size - 1; i++)
                    pc[i] = this->field[i];
                delete [] this->field;
                pc[this->size - 1] = &ob;
                this->field = pc;
            }
        }
        else
        {
            this->size++;
            object **pc = new object*[this->size];
            pc[this->size - 1] = &ob;
            this->field = pc;
        }
        return 1;
}

int object_collection::remove()
{
    if (this->size > 1)
    {
        this->size--;
        object **pc = new object*[this->size];
        for(int i = 0; i < this->size; i++)
            pc[i] = this->field[i+1];
        delete [] this->field;
        this->field = pc;
    }
    else
    {
        this->size = 0;
        this->field = nullptr;
    }
    return 1;
}


int object_collection::clean()
{
    if (this->field)
        {
            delete [] this->field;
            this->field = nullptr;
            this->size = 0;
        }
        return 1;
}


int object_collection::get_size()
{
    return this->size;
}


object_collection::~object_collection()
{
    this->size = 0;
    delete [] this->field;
    this->field = nullptr;
}


int object_collection::input_from_file(const string &fname)
{
    string name;
    int volume;
    int price;
    ifstream file(fname);

    if(this->field)
    {
        delete [] this->field;
        this->field = nullptr;
        this->field = 0;
    }
    if (file.is_open())
    {
        while(!file.eof())
        {
            file >> name;
            file >> volume;
            file >> price;
            cout << name << endl;
            cout << volume << endl;
            cout << price << endl;
            auto ob = new object(name, volume, price);
            if ((ob->get_volume()!= 0) && (ob->get_volume()>0) && (ob->get_price()>=0))
                this->add_elem(*ob);
        }
        file.close();
    }
    return 1;
}

int object_collection::ms_input_from_file(const string &fname)
{
    string name;
    int volume;
    int price;
    ifstream file(fname);

    if(this->field)
    {
        delete [] this->field;
        this->field = nullptr;
        this->field = 0;
    }
    if (file.is_open())
    {
        while(!file.eof())
        {
            file >> name;
            file >> volume;
            file >> price;
            cout << name << endl;
            cout << volume << endl;
            cout << price << endl;

            auto stack = new money_stack(name, volume, price);
            if ((stack->get_volume()!= 0) && (stack->get_volume()>0) && (stack->get_price()>=0))
                this->add_elem(*stack);
        }
        file.close();
    }
    return 1;
}



int object_collection::output_to_file(const string &fname)
{
    ofstream fout(fname);

    for(int i = 0;i < this->size;i++)
    {
        fout << "#" << i+1 << endl;
        fout << this->field[i]->get_name()<< endl;
        fout << this->field[i]->get_volume() << endl;
        fout << this->field[i]->get_price() << endl;
    }
    fout.close();
    return 1;
}

int object_collection::ms_output_to_file(const string &fname)
{
    ofstream fout(fname);

    for(int i = 0;i < this->size;i++)
    {
        fout << "#" << i+1 << endl;
        fout << this->field[i]->get_name()<< endl;
        fout << this->field[i]->get_data("new") << endl;
        fout << this->field[i]->get_price() << endl;
    }
    fout.close();
    return 1;
}
