#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>
#include <QCloseEvent>
#include <QVector>
#include "qcustomplot.h"

extern "C" {
#include "./../s21_smartcalc.h"
}

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
    void slotMousePress(QMouseEvent *event);
    void slotMouseMove(QMouseEvent *event);
    void onMouseWheel();

    void build_plot(QString expression);
    double calculate(QString expression, double variable);
    int check_symbol(QString expression, QChar first, QChar second);
    void change_label_visible(bool decision);

private slots:
    void on_trace_enable_clicked();

private:
    Ui::graphics *ui;
    QCPItemTracer *tracer;
    double last_step;
    int tracer_visible;
    QString last_expr;
    int graph_nums;

    QVector<double> x, y;
    double current_x_min, current_x_max, current_y_min, current_y_max;
    double xBegin, xEnd, yBegin, yEnd, h, X;
    int N;
};

#endif // GRAPHICS_H