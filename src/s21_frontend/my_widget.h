#ifndef MY_WIDGET_H
#define MY_WIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QApplication>
#include <QPushButton>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QComboBox>

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
    QComboBox* getUi_type();
    int containsOnlyDigits(const QString &str);
    int check_fraction_length(const QString &text, int length);

private slots:
    void on_add_to_table_clicked();
    void on_clean_table_clicked();
    int onOperEditTextChanged(const QString &text);

private:
    Ui::my_widget *ui;
};

#endif // MY_WIDGET_H
