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

void second_window::insert_data(object_collection obj_collection, int size) const
{
    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item;
    for (int i=0; i< size; i++)
    {

        item = new QStandardItem(QString("#" + QString::number(i+1)));
        obj_collection.set_iterator_index(i+1);
        model->appendRow(item);

        item = new QStandardItem(QString(QString::fromStdString(obj_collection.get_iterator_value().get_name())));
        model->appendRow(item);

        item = new QStandardItem(QString(QString::number(obj_collection.get_iterator_value().get_price())));
        model->appendRow(item);

        item = new QStandardItem(QString(QString::number(obj_collection.get_iterator_value().get_volume())));
        model->appendRow(item);

    }
    ui->listView->setModel(model);
}


void second_window::insert_data_ms(object_collection ms_collection, int size) const
{
    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item;
    for (int i=0; i< size; i++)
    {

        item = new QStandardItem(QString("#" + QString::number(i+1)));
        ms_collection.set_iterator_index(i+1);
        model->appendRow(item);

        item = new QStandardItem(QString(QString::fromStdString(ms_collection.get_iterator_value().get_name())));
        model->appendRow(item);

        item = new QStandardItem(QString(QString::number(ms_collection.get_iterator_value().get_price())));
        model->appendRow(item);

        item = new QStandardItem(QString(QString::number(ms_collection.get_iterator_value().get_volume())));
        model->appendRow(item);

    }
    ui->listView->setModel(model);
}



