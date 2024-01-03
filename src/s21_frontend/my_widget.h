#ifndef MY_WIDGET_H
#define MY_WIDGET_H

#include <QWidget>
#include <QTableWidget>

namespace Ui {
class my_widget;
}

class my_widget : public QWidget
{
    Q_OBJECT

public:
    explicit my_widget(QWidget *parent = nullptr);
    ~my_widget();

public slots:
    QTableWidget* getTableWidget();

private slots:
    void on_add_to_table_clicked();
    void on_clean_table_clicked();

private:
    Ui::my_widget *ui;
};

#endif // MY_WIDGET_H
