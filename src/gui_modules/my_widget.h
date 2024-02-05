#ifndef MY_WIDGET_H
#define MY_WIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QApplication>
#include <QPushButton>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QComboBox>
enum styles {WRONG_EXPR = 1, CORRECT_EXPR = 0};

namespace Ui {
class my_widget;
}

class my_widget : public QWidget
{
    Q_OBJECT

public:
    explicit my_widget(QWidget *parent = nullptr);
    ~my_widget();
    QString correct_style;
    QString wrong_style;

public slots:
    QTableWidget* getTableWidget();
    QComboBox* getUi_type();
    QLineEdit* getUi_sum();

private slots:
    void on_add_to_table_clicked();
    void on_clean_table_clicked();
    int onOperEditTextChanged(const QString &text);

private:
    Ui::my_widget *ui;
};

#endif // MY_WIDGET_H
