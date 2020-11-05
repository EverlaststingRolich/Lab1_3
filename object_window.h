#ifndef OBJECT_WINDOW_H
#define OBJECT_WINDOW_H

#include <QDialog>
#include <object_collection.h>

namespace Ui {
class object_window;
}

class object_window : public QDialog
{
    Q_OBJECT

public:
    explicit object_window(QWidget *parent = nullptr);
    ~object_window();

private slots:
    void on_add_clicked();


    void on_view_collection_clicked();

private:
    object_collection obj_collection;
    Ui::object_window *ui;
};

#endif // OBJECT_WINDOW_H
