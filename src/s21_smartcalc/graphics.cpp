#include "graphics.h"
#include "ui_graphics.h"

extern "C" {
#include "../calculations/s21_main/main.c"
#include "../calculations/s21_main/validation.c"
#include "../calculations/s21_main/notation.c"
#include "../calculations/s21_main/checks.c"
#include "../calculations/s21_main/comparison.c"
#include "../calculations/s21_main/math_operations.c"
}

graphics::graphics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::graphics)
{
    ui->setupUi(this);
}

graphics::~graphics()
{
    delete ui;
}

void graphics::closeEvent(QCloseEvent *event)
{
    emit graphWindowClosed();
    event->accept();
}

double graphics::calculate(QString expression, double variable) {
    QByteArray byteArray = expression.toUtf8();
    char* charArray = byteArray.data();
    double res = calculation(charArray, variable);
    return res;
}

int graphics::check_brackets(QString expression)
{
    int count_open = 0;
    int count_close = 0;
    for(int i = 0; i < expression.length(); i++) {
        if(expression[i] == '(') {
            count_open++;
        } else if(expression[i] == ')') {
            count_close++;
        }
    }
    return (count_open != count_close) ? 1 : 0;
}

void graphics::build_plot(QString expression)
{
    if(expression.length() > 0) {
        ui->Table->clearItems();
        x.clear();
        y.clear();

        h = 0.001;
        xBegin = ui->x_beg->text().toDouble();
        xEnd = ui->x_end->text().toDouble() + h;
        yBegin = ui->y_beg->text().toDouble();
        yEnd = ui->y_end->text().toDouble() + h;
        ui->Table->xAxis->setRange(xBegin - 1, xEnd + 1);
        ui->Table->yAxis->setRange(yBegin, yEnd);

        N = (xEnd - xBegin)/h + 2;

        for(X = xBegin; X <= xEnd; X += h)
        {
            x.push_back(X);
            y.push_back(calculate(expression, X));
        }

        ui->Table->addGraph();
        ui->Table->graph(0)->setData(x, y);
        ui->Table->replot();
    }
}
