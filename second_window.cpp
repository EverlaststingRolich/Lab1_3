#include "second_window.h"
#include "ui_second_window.h"
#include "object_collection.h"
#include <QStandardItem>
#include <QStandardItemModel>


second_window::second_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::second_window)
{
    ui->setupUi(this);
}

second_window::~second_window()
{
    delete ui;
}

void second_window::insert_data(object_collection* collection, int size) const
{
    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item;
    for (int i=0; i< size; i++)
    {

        item = new QStandardItem(QString("#" + QString::number(i+1)));
        model->appendRow(item);

        item = new QStandardItem(QString(QString::fromStdString(collection->get_iterator()[i]->get_name())));
        model->appendRow(item);

        item = new QStandardItem(QString(QString::number(collection->get_iterator()[i]->get_price())));
        model->appendRow(item);

        item = new QStandardItem(QString(QString::number(collection->get_iterator()[i]->get_volume())));
        model->appendRow(item);


    }
    ui->listView->setModel(model);
}


void second_window::insert_data_ms(object_collection* collection, int size) const
{
    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item;
    for (int i=0; i< size; i++)
    {

        item = new QStandardItem(QString("#" + QString::number(i+1)));
        model->appendRow(item);

        item = new QStandardItem(QString(QString::fromStdString(collection->get_iterator()[i]->get_name())));
        model->appendRow(item);

        item = new QStandardItem(QString(QString::number(collection->get_iterator()[i]->get_data("price"))));
        model->appendRow(item);

        item = new QStandardItem(QString(QString::number(collection->get_iterator()[i]->get_data("new"))));
        model->appendRow(item);

    }
    ui->listView->setModel(model);
}



