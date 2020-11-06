#include "object_window.h"
#include "ui_object_window.h"
#include <QMessageBox>
#include <string>
#include <stdlib.h>
#include <QStandardItem>
#include <QStandardItemModel>
#include "mainwindow.h"
#include <fstream>
#include <second_window.h>

object_window::object_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::object_window)
{
    ui->setupUi(this);
}

object_window::~object_window()
{
    delete ui;
}


void object_window::on_add_clicked()
{
    std:: string name = ui->object_name->text().toStdString();
    int volume  = atoi(ui->object_volume->text().toStdString().c_str());
    int price  = atoi(ui->object_price->text().toStdString().c_str());
    int pos = atoi(ui->object_position->text().toStdString().c_str());
    auto obj = new object(name, volume, price);

    int size_of_collection = this->obj_collection.get_size();

    if(pos == 0 || volume == 0 || price == 0 || pos > size_of_collection+1)

        QMessageBox::critical(this, "Add", "Wrong data. Please, try again");
    else
    {
        this->obj_collection.add_elem(*obj, pos);
        QMessageBox::information(this, "Add", "You add new purchase");
    }
}

void object_window::on_view_collection_clicked()
{
    if(this->obj_collection.get_iterator_index() && this->obj_collection.get_size())
    {
        second_window window;
        window.setModal(true);
        window.insert_data(this->obj_collection, this->obj_collection.get_size());
        window.exec();
    }
    else
        QMessageBox::critical(this,"Show", "There is no data to show");
}


void object_window::on_delete_number_clicked()
{
    int number = atoi(ui->object_number->text().toStdString().c_str());
    if (number == 0 || number > this->obj_collection.get_size())
        QMessageBox::critical(this, "Delete object", "Wrong number off element");
    else
    {
        if(this->obj_collection.get_iterator_index() && this->obj_collection.get_size())
        {
            this->obj_collection.remove(number);
        }

        else
        {
            QMessageBox::information(this, "Delete object", "There is no data to delete");
        }
    }
}

void object_window::on_delete_list_clicked()
{
    if(this->obj_collection.get_iterator_index() && this->obj_collection.get_size())
    {
        this->obj_collection.clean();
        QMessageBox::information(this, "Clean", "You delete all list");
    }
    else
        QMessageBox::critical(this,"Clear", "There is no data to clean");
}

void object_window::on_size_of_collection_clicked()
{
    if(this->obj_collection.get_iterator_index() && this->obj_collection.get_size())
    {
        QMessageBox::information(this, "Size", "The size of the list:   " + QString::number(this->obj_collection.get_size()));
    }
    else
        QMessageBox::critical(this,"Size", "There is no elements at list");
}




void object_window::on_input_file_clicked()
{
    this->obj_collection.from_file(ui->file_input_name->text().toStdString());
    QMessageBox::information(this, "Input from file", "Success input from file");
}



void object_window::on_output_file_clicked()
{
    if(this->obj_collection.get_iterator_index() && this->obj_collection.get_size())
    {
        this->obj_collection.to_file(ui->file_output_name->text().toStdString());
        QMessageBox::information(this, "Output to file", "Success output to file");
    }
    else
        QMessageBox::critical(this,"Output to file", "There is no list");
}
