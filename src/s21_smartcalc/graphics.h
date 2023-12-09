#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>
#include <QCloseEvent>
#include <QVector>

namespace Ui {
class graphics;
}

class graphics : public QWidget
{
    Q_OBJECT

public:
    explicit graphics(QWidget *parent = nullptr);
    ~graphics();

signals:
    void graphWindowClosed();

protected:
    void closeEvent(QCloseEvent *event) override;

public slots:
    void build_plot(QString expression);
    double calculate(QString expression, double variable);
    int check_symbol(QString expression, QChar symbol);

private:
    Ui::graphics *ui;
    QVector<double> x, y;
    double xBegin, xEnd, yBegin, yEnd, h, X;
    int N;
};

#endif // GRAPHICS_H
