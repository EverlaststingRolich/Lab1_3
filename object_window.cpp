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
    if(obj->get_volume() == 0)
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





