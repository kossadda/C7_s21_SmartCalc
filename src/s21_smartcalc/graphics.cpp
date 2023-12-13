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

#define s21_is_nan(X) ((X) != (X))

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
    std::string str = expression.toStdString();
    char *c_str = (char *)str.c_str();
    double res = calculation(c_str, variable);
    return res;
}

int graphics::check_symbol(QString expression, QChar symbol)
{
    int count_symbol = 0;
    for(int i = 0; i < expression.length(); i++) {
        if(expression[i] == symbol) {
            count_symbol++;
        }
    }
    return count_symbol;
}

void graphics::build_plot(QString expression)
{
    double result = 0;
    ui->Table->clearItems();
    x.clear();
    y.clear();

    h = 0.01;
    xBegin = ui->x_beg->text().toDouble();
    xEnd = ui->x_end->text().toDouble() + h;
    yBegin = ui->y_beg->text().toDouble();
    yEnd = ui->y_end->text().toDouble() + h;
    ui->Table->xAxis->setRange(xBegin - 1, xEnd + 1);
    ui->Table->yAxis->setRange(yBegin, yEnd);

    N = (xEnd - xBegin)/h + 2;

    for(X = xBegin; X <= xEnd; X += h)
    {
        result = calculate(expression, X);
        x.push_back(X);
        y.push_back(result);
    }

    ui->Table->addGraph();
    ui->Table->graph(0)->setData(x, y);
    ui->Table->replot();
}

// void graphics::build_plot(QString expression)
// {
//     if(expression.length() > 0) {
//         ui->Table->clearItems();
//         x.clear();
//         y.clear();

//         h = 0.01;
//         xBegin = ui->x_beg->text().toDouble();
//         xEnd = ui->x_end->text().toDouble() + h;
//         yBegin = ui->y_beg->text().toDouble();
//         yEnd = ui->y_end->text().toDouble() + h;
//         ui->Table->xAxis->setRange(xBegin - 1, xEnd + 1);
//         ui->Table->yAxis->setRange(yBegin, yEnd);

//         N = (xEnd - xBegin)/h + 2;

//         for(X = xBegin; X <= xEnd; X += h)
//         {
//             x.push_back(X);
//             y.push_back(calculate(expression, X));
//         }

//         ui->Table->addGraph();
//         ui->Table->graph(0)->setData(x, y);

//         ui->Table->graph(0)->setLineStyle((QCPGraph::LineStyle)QCPGraph::lsNone);
//         ui->Table->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc , 3));

//         ui->Table->replot();
//     }
// }
