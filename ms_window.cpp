#include "ms_window.h"
#include "ui_ms_window.h"
#include <QMessageBox>
#include <string>
#include <stdlib.h>
#include <second_window.h>
#include <QStandardItem>
#include <QStandardItemModel>
#include "money_stack.h"
#include "money_stack.cpp"
#include "mainwindow.h"
#include <fstream>

ms_window::ms_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ms_window)
{
    ui->setupUi(this);
}

ms_window::~ms_window()
{
    delete ui;
}


void ms_window::on_add_ms_clicked()
{
    std:: string name = ui->ms_name->text().toStdString();
    int price  = atoi(ui->ms_price->text().toStdString().c_str());
    int pos = atoi(ui->ms_pos->text().toStdString().c_str());
    int volume = find_new_volume(price);;
    auto stack = new money_stack(name, volume, price);

    int size_of_collection = this->ms_collection.get_size();

    if(pos == 0 || volume == 0 || price == 0 || pos > size_of_collection+1)

        QMessageBox::critical(this, "Add", "Wrong data. Please, try again");
    else
    {
        this->ms_collection.add_elem(*stack, pos);
        QMessageBox::information(this, "Add", "You add new purchase");
    }
}


void ms_window::on_view_ms_collection_clicked()
{
    if(this->ms_collection.get_iterator_index() && this->ms_collection.get_size())
    {
        second_window window;
        window.setModal(true);
        window.insert_data_ms(this->ms_collection, this->ms_collection.get_size());
        window.exec();
    }
    else
        QMessageBox::critical(this,"Show", "There is no data to show");
}



void ms_window::on_delete_ms_number_clicked()
{
    int number = atoi(ui->number->text().toStdString().c_str());
    if (number == 0 || number > this->ms_collection.get_size())
        QMessageBox::critical(this, "Delete object", "Wrong number off element");
    else
    {
        if(this->ms_collection.get_iterator_index() && this->ms_collection.get_size())
        {
            this->ms_collection.remove(number);
        }

        else
        {
            QMessageBox::information(this, "Delete object", "There is no data to delete");
        }
    }
}


void ms_window::on_delete_list_clicked()
{
    if(this->ms_collection.get_iterator_index() && this->ms_collection.get_size())
    {
        this->ms_collection.clean();
        QMessageBox::information(this, "Clean", "You delete all list");
    }
    else
        QMessageBox::critical(this,"Clear", "There is no data to clean");
}


void ms_window::on_size_clicked()
{
    if(this->ms_collection.get_iterator_index() && this->ms_collection.get_size())
    {
        QMessageBox::information(this, "Size", "The size of the list:   " + QString::number(this->ms_collection.get_size()));
    }
    else
        QMessageBox::critical(this,"Size", "There is no elements at list");
}

void ms_window::on_confirm_input_clicked()
{
    this->ms_collection.from_file(ui->input->text().toStdString());

    QMessageBox::information(this, "Input from file", "Success input from file");
}



void ms_window::on_confirm_output_clicked()
{
    if(this->ms_collection.get_iterator_index() && this->ms_collection.get_size())
    {
        this->ms_collection.to_file(ui->output->text().toStdString());
        QMessageBox::information(this, "Output to file", "Success output to file");
    }
    else
        QMessageBox::critical(this,"Output to file", "There is no list");
}

