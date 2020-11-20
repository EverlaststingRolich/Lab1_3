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


void object_window::on_view_collection_clicked()
{
    if(this->obj_collection.get_iterator() && this->obj_collection.get_size())
    {
        second_window window;
        window.setModal(true);
        window.insert_data(&this->obj_collection, this->obj_collection.get_size());
        window.exec();
    }
    else
        QMessageBox::critical(this,"Show", "There is no data to show");
}


void object_window::on_delete_number_clicked()
{
    if(this->obj_collection.get_iterator() && this->obj_collection.get_size())
    {
        this->obj_collection.remove();
        QMessageBox::information(this, "Pop", "You pop first purchase");
    }
    else
        QMessageBox::critical(this,"Pop", "There is no data to pop");
}



void object_window::on_delete_list_clicked()
{
    if(this->obj_collection.get_iterator() && this->obj_collection.get_size())
    {
        this->obj_collection.clean();
        QMessageBox::information(this, "Clean", "You delete all queue");
    }
    else
        QMessageBox::critical(this,"Clear", "There is no data to clean");
}


void object_window::on_size_of_collection_clicked()
{
    if(this->obj_collection.get_iterator() && this->obj_collection.get_size())
    {
        QMessageBox::information(this, "Size", "The size of the queue is " + QString::number(this->obj_collection.get_size()));
    }
    else
        QMessageBox::critical(this,"Size", "There is no queue");
}





void object_window::on_add_clicked()
{
    std:: string name = ui->object_name->text().toStdString();
    int volume  = atoi(ui->object_volume->text().toStdString().c_str());
    int price  = atoi(ui->object_price->text().toStdString().c_str());
    auto obj = new object(name, volume, price);

    if(volume <= 0 || price <= 0)

        QMessageBox::critical(this, "Add", "Wrong data. Please, try again");
    else
    {
        this->obj_collection.add_elem(*obj);
        QMessageBox::information(this, "Add", "You add new purchase");
    }
}



void object_window::on_input_file_clicked()
{
    this->obj_collection.input_from_file(ui->file_input_name->text().toStdString());
    QMessageBox::information(this, "Input from file", "Success input from file");
}



void object_window::on_output_file_clicked()
{
    if(this->obj_collection.get_iterator() && this->obj_collection.get_size())
    {
        this->obj_collection.output_to_file(ui->file_output_name->text().toStdString());
        QMessageBox::information(this, "Output to file", "Success output to file");
    }
    else
        QMessageBox::critical(this,"Output to file", "There is no queue");
}
