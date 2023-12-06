#ifndef MY_WIDGET_H
#define MY_WIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDateEdit>
#include <QLineEdit>

namespace Ui {
class my_widget;
}

class my_widget : public QWidget
{
    Q_OBJECT

public:
    explicit my_widget(QWidget *parent = nullptr);
    ~my_widget();

    QComboBox* getComboBox() const;

private slots:
    void onAddButtonClicked();
    void onRemoveButtonClicked();

private:
    Ui::my_widget *ui;
    QComboBox *comboBox;
    QPushButton *addButton;
    QPushButton *removeButton;
    QDateEdit *dateEdit; // Добавлено для ввода даты
    QLineEdit *amountLineEdit; // Добавлено для ввода суммы
};

#endif // MY_WIDGET_H
