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
    ui(new Ui::graphics),
    tracer(nullptr),
    last_step(0.01)
{
    ui->setupUi(this);
    ui->info_label_x->setVisible(false);
    ui->info_label_y->setVisible(false);
    ui->x_trace->setVisible(false);
    ui->y_trace->setVisible(false);
    connect(ui->Table, &QCustomPlot::mousePress, this, &graphics::slotMousePress);
    connect(ui->Table, &QCustomPlot::mouseMove, this, &graphics::slotMouseMove);
}

graphics::~graphics()
{
    if (tracer) {
        delete tracer;
        tracer = nullptr;
    }
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

void graphics::slotMousePress(QMouseEvent *event)
{
    if(tracer && last_step != ui->step->text().toDouble() && ui->step->text().toDouble() != 0) {
        tracer = nullptr;
        tracer = new QCPItemTracer(ui->Table);
        tracer->setGraph(ui->Table->graph(0));
    }
    if(tracer && tracer->visible()) {
        double coordX = ui->Table->xAxis->pixelToCoord(event->pos().x());

        QVector<double> x(2), y(2);
        x[0] = coordX;
        y[0] = ui->y_beg->text().toDouble();
        x[1] = coordX;
        y[1] = ui->y_end->text().toDouble();

        tracer->setGraphKey(coordX);

        last_step = ui->step->text().toDouble();
        ui->x_trace->setText(QString::number(tracer->position->key()));
        ui->y_trace->setText(QString::number(tracer->position->value()));

        ui->Table->replot();
    }
}

void graphics::slotMouseMove(QMouseEvent *event)
{
    if(tracer && tracer->visible()) {
        if(QApplication::mouseButtons()) slotMousePress(event);
    }
}

void graphics::build_plot(QString expression)
{
    if(ui->step->text().toDouble() != 0) {
        if(tracer && last_expr != expression) {
            last_step = 0;
        }
        double result = 0;
        ui->Table->clearItems();
        x.clear();
        y.clear();

        h = ui->step->text().toDouble();
        xBegin = ui->x_beg->text().toDouble();
        xEnd = ui->x_end->text().toDouble();
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

        ui->Table->addGraph(ui->Table->xAxis, ui->Table->yAxis);
        ui->Table->graph(0)->setData(x, y);
        ui->Table->replot();
    }
}

void graphics::on_trace_enable_clicked()
{
    if(tracer) {
        tracer->setVisible(!tracer->visible());
        if(ui->x_trace->isVisible()) {
            ui->trace_enable->setStyleSheet("QPushButton {background-color: rgb(0, 119, 171);} QPushButton:pressed {background-color: rgb(175, 97, 33);}");
            ui->info_label_x->setVisible(false);
            ui->info_label_y->setVisible(false);
            ui->x_trace->setVisible(false);
            ui->y_trace->setVisible(false);
        } else {
            ui->trace_enable->setStyleSheet("QPushButton {background-color: rgb(175, 97, 33);} QPushButton:pressed {background-color: rgb(50, 50, 50);}");
            ui->info_label_x->setVisible(true);
            ui->info_label_y->setVisible(true);
            ui->x_trace->setVisible(true);
            ui->y_trace->setVisible(true);
            ui->x_trace->setText("0");
            ui->y_trace->setText("0");
        }
    } else {
        if(ui->Table->graphCount() > 0) {
            tracer = new QCPItemTracer(ui->Table);
            tracer->setGraph(ui->Table->graph(0));
            ui->trace_enable->setStyleSheet("QPushButton {background-color: rgb(175, 97, 33);} QPushButton:pressed {background-color: rgb(50, 50, 50);}");
            ui->info_label_x->setVisible(true);
            ui->info_label_y->setVisible(true);
            ui->x_trace->setVisible(true);
            ui->y_trace->setVisible(true);
        }
    }
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

