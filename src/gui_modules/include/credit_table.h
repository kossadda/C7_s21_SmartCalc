#ifndef CREDIT_TABLE_H
#define CREDIT_TABLE_H

#include <QWidget>

namespace Ui {
class credit_table;
}

class credit_table : public QWidget
{
    Q_OBJECT

public:
    explicit credit_table(QWidget *parent = nullptr);
    ~credit_table();

    Ui::credit_table* getUi() const;

private:
    Ui::credit_table *ui;
};

#endif // CREDIT_TABLE_H
