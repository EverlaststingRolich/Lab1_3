#ifndef MS_WINDOW_H
#define MS_WINDOW_H

#include <QDialog>
#include <object_collection.h>


namespace Ui {
class ms_window;
}

class ms_window : public QDialog
{
    Q_OBJECT

public:
    explicit ms_window(QWidget *parent = nullptr);
    ~ms_window();

private slots:
    void on_add_ms_clicked();

    void on_view_ms_collection_clicked();

    void on_delete_ms_number_clicked();

    void on_delete_list_clicked();

    void on_size_clicked();

    void on_confirm_input_clicked();

    void on_confirm_output_clicked();

    void on_pushButton_clicked();

private:
    object_collection ms_collection;
    object_collection *ms_collection_dial;
    Ui::ms_window *ui;
};

#endif // MS_WINDOW_H
