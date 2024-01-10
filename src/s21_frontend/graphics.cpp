#include "graphics.h"
#include "ui_graphics.h"

graphics::graphics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::graphics),
    tracer(nullptr),
    last_step(0.01),
    tracer_visible(0),
    graph_nums(0),
    xBegin(0),
    xEnd(0),
    yBegin(0),
    yEnd(0)
{
    ui->setupUi(this);
    change_label_visible(false);
    connect(ui->Table, &QCustomPlot::mousePress, this, &graphics::slotMousePress);
    connect(ui->Table, &QCustomPlot::mouseMove, this, &graphics::slotMouseMove);
    connect(ui->Table, &QCustomPlot::mouseWheel, this, &graphics::onMouseWheel);
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

void graphics::onMouseWheel()
{
    QCPRange yRange = ui->Table->yAxis->range();
    QCPRange xRange = ui->Table->xAxis->range();

    if(ui->Table->graphCount() > 0) {
        if (yRange.size() > yEnd - yBegin || xRange.size() > xEnd - xBegin) {
            ui->Table->xAxis->setRange(xBegin, xEnd);
            ui->Table->yAxis->setRange(yBegin, yEnd);
        }
    }
}


void graphics::slotMousePress(QMouseEvent *event)
{
    if(tracer && ((last_step != ui->step->text().toDouble() && ui->step->text().toDouble() != 0) || tracer_visible)) {
        tracer = nullptr;
        tracer = new QCPItemTracer(ui->Table);
        tracer->setGraph(ui->Table->graph(0));
        tracer->setVisible(ui->x_trace->isVisible());
        tracer_visible = 0;
    }
    if(tracer && ui->x_trace->isVisible()) {
        double coordX = ui->Table->xAxis->pixelToCoord(event->pos().x());

        QVector<double> x(2), y(2);
        x[0] = coordX;
        y[0] = ui->y_beg->text().toDouble();
        x[1] = coordX;
        y[1] = ui->y_end->text().toDouble();

        tracer->setGraphKey(coordX);

        last_step = ui->step->text().toDouble();
        ui->x_trace->setText(QString::number(tracer->position->key()));
        ui->y_trace->setText(QString::number(tracer->position->value(), 'f', 5));

        ui->Table->replot();
    }
}

void graphics::slotMouseMove(QMouseEvent *event)
{
    if(tracer && ui->x_trace->isVisible()) {
        if(QApplication::mouseButtons()) slotMousePress(event);
    }
}

void graphics::build_plot(QString expression)
{
    if(ui->step->text().toDouble() != 0) {
        if(tracer && last_expr != expression) {
            tracer_visible = 1;
        }
        ui->x_trace->setText("0");
        ui->y_trace->setText("0");
        double prev = calculate(expression, xBegin);
        double result = 0;
        double diff = 0;
        ui->Table->clearItems();
        x.clear();
        y.clear();

        h = ui->step->text().toDouble();
        xBegin = ui->x_beg->text().toDouble();
        xEnd = ui->x_end->text().toDouble();
        yBegin = ui->y_beg->text().toDouble();
        yEnd = ui->y_end->text().toDouble() + h;
        ui->Table->xAxis->setRange(xBegin, xEnd);
        ui->Table->yAxis->setRange(yBegin, yEnd);

        N = (xEnd - xBegin)/h + 2;

        for(X = xBegin; X <= xEnd; X += h)
        {
            result = calculate(expression, X);
            diff = fabs(result - prev);
            x.push_back(X);
            if(result < yEnd && result > yBegin && diff < 200) {
                y.push_back(result);
            } else {
                y.push_back(std::nan(""));
            }
            prev = result;
        }

        ui->Table->addGraph(ui->Table->xAxis, ui->Table->yAxis);
        ui->Table->graph(0)->setData(x, y);

        ui->Table->replot();
        ui->Table->setInteraction(QCP::iRangeZoom, true);
        if(!ui->x_trace->isVisible()) {
            ui->Table->setInteraction(QCP::iRangeDrag, true);
        }
    }
}

// void graphics::build_plot(QString expression)
// {
//     if(ui->step->text().toDouble() != 0) {
//         if(tracer && last_expr != expression) {
//             tracer_visible = 1;
//         }
//         double result = 0;
//         ui->Table->clearItems();
//         ui->Table->clearGraphs();
//         graph_nums = 0;

//         h = ui->step->text().toDouble();
//         xBegin = ui->x_beg->text().toDouble();
//         xEnd = ui->x_end->text().toDouble();
//         yBegin = ui->y_beg->text().toDouble();
//         yEnd = ui->y_end->text().toDouble() + h;
//         ui->Table->xAxis->setRange(xBegin, xEnd);
//         ui->Table->yAxis->setRange(yBegin, yEnd);

//         N = (xEnd - xBegin)/h + 2;
//         X = xBegin;
//         bool graph_this = 0;

//         for(; X <= xEnd;)
//         {
//             QVector<double> x, y;
//             for( ; X <= xEnd ; ) {
//                 X += h;
//                 result = calculate(expression, X);
//                 if(result < yEnd && result > yBegin) {
//                     x.push_back(X);
//                     y.push_back(result);
//                 } else {
//                     graph_this = 1;
//                     break;
//                 }
//             }
//             if(graph_this && !x.isEmpty()) {
//                 allX.push_back(x);
//                 allY.push_back(y);
//                 ui->Table->addGraph(ui->Table->xAxis, ui->Table->yAxis);
//                 ui->Table->graph(graph_nums)->setData(allX.back(), allY.back());
//                 graph_nums++;
//                 graph_this = 0;
//             }
//         }
//         ui->Table->replot();
//         ui->Table->setInteraction(QCP::iRangeZoom, true);
//         if(!ui->x_trace->isVisible()) {
//             ui->Table->setInteraction(QCP::iRangeDrag, true);
//         }
//     }
// }

void graphics::on_trace_enable_clicked()
{
    if(tracer) {
        if(!tracer_visible) {
            tracer->setVisible(!tracer->visible());
        }
        if(ui->x_trace->isVisible()) {
            ui->trace_enable->setStyleSheet("QPushButton {background-color: rgb(175, 97, 33); border-radius: 10px; } QPushButton:pressed {background-color: rgb(0, 146, 209);}");
            ui->Table->setInteraction(QCP::iRangeDrag, true);
            change_label_visible(false);
        } else {
            ui->trace_enable->setStyleSheet("QPushButton {background-color: rgb(0, 146, 209); border-radius: 10px; } QPushButton:pressed {background-color: rgb(175, 97, 33);}");
            ui->Table->setInteraction(QCP::iRangeDrag, false);
            change_label_visible(true);
        }
    } else {
        if(ui->Table->graphCount() > 0) {
            tracer = new QCPItemTracer(ui->Table);
            tracer->setGraph(ui->Table->graph(0));
            ui->trace_enable->setStyleSheet("QPushButton {background-color: rgb(0, 146, 209); border-radius: 10px; } QPushButton:pressed {background-color: rgb(175, 97, 33);}");
            ui->Table->setInteraction(QCP::iRangeDrag, false);
            change_label_visible(true);
        }
    }
    ui->Table->replot();
}

void graphics::change_label_visible(bool decision) {
    ui->info_label_x->setVisible(decision);
    ui->info_label_y->setVisible(decision);
    ui->x_trace->setVisible(decision);
    ui->y_trace->setVisible(decision);
}
