#include "./../include/graphics.h"

#include <QtGlobal>

#include "./ui_graphics.h"

graphics::graphics(QWidget *parent)
    : QWidget(parent),
      correct_style(
          "QLineEdit {border-radius: 10px;padding: 0 8px;background-color: "
          "rgb(226, 226, 226);color:black;}"),
      wrong_style(
          "QLineEdit {border-radius: 10px;padding: 0 8px;background-color: "
          "rgba(255, 0, 0, 100);color:black;}"),
      ui(new Ui::graphics),
      tracer(nullptr),
      last_step(0.01),
      tracer_visible(0),
      graph_nums(0),
      current_x_min(0),
      current_x_max(0),
      current_y_min(0),
      current_y_max(0),
      xBegin(0),
      xEnd(0),
      yBegin(0),
      yEnd(0) {
  ui->setupUi(this);
  change_label_visible(false);
  connect(ui->Table, &QCustomPlot::mousePress, this, &graphics::slotMousePress);
  connect(ui->Table, &QCustomPlot::mouseMove, this, &graphics::slotMouseMove);
  connect(ui->Table, &QCustomPlot::mouseWheel, this, &graphics::onMouseWheel);
  connect(ui->step, &QLineEdit::textChanged, this,
          &graphics::onStepEditTextChanged);
  connect(ui->x_beg, &QLineEdit::textChanged, this,
          &graphics::onXMinTextChanged);
  connect(ui->x_end, &QLineEdit::textChanged, this,
          &graphics::onXMaxTextChanged);
  connect(ui->y_beg, &QLineEdit::textChanged, this,
          &graphics::onYMinTextChanged);
  connect(ui->y_end, &QLineEdit::textChanged, this,
          &graphics::onYMaxTextChanged);
}

graphics::~graphics() {
  if (tracer) {
    delete tracer;
    tracer = nullptr;
  }
  delete ui;
}

void graphics::closeEvent(QCloseEvent *event) {
  emit graphWindowClosed();
  event->accept();
}

double graphics::calculate(QString expression, double variable) {
  std::string str = expression.toStdString();
  char *c_str = (char *)str.c_str();
  double res = calculation(c_str, variable);
  return res;
}

int graphics::compare_max_min_x_y() {
  int valid = 0;

  valid += onStepEditTextChanged(ui->step->text());
  valid += onXMinTextChanged(ui->x_beg->text());
  valid += onXMaxTextChanged(ui->x_end->text());
  valid += onYMinTextChanged(ui->y_beg->text());
  valid += onYMaxTextChanged(ui->y_end->text());

  if (ui->x_beg->text().toDouble() >= ui->x_end->text().toDouble()) {
    ui->x_beg->setStyleSheet(wrong_style);
    ui->x_end->setStyleSheet(wrong_style);
    valid = 1;
  } else {
    ui->x_beg->setStyleSheet(correct_style);
    ui->x_end->setStyleSheet(correct_style);
  }

  if (ui->y_beg->text().toDouble() >= ui->y_end->text().toDouble()) {
    ui->y_beg->setStyleSheet(wrong_style);
    ui->y_end->setStyleSheet(wrong_style);
    valid = 1;
  } else {
    ui->y_beg->setStyleSheet(correct_style);
    ui->y_end->setStyleSheet(correct_style);
  }

  return valid;
}

int graphics::onStepEditTextChanged(const QString &text) {
  int valid = 1;

  static const QRegularExpression regex("^[0-9]{1,3}(\\.[0-9]{1,3})?$");
  QRegularExpressionMatch match = regex.match(text);

  if (text.length() == 0) {
    ui->step->setStyleSheet(wrong_style);
    ui->step->setPlaceholderText("Enter step");
  } else if (match.hasMatch() && text.toDouble() <= 100 && text.toDouble() &&
             !(text[0] == '0' && text[1] != '.')) {
    ui->step->setStyleSheet(correct_style);
    valid = 0;
  } else {
    ui->step->setStyleSheet(wrong_style);
  }

  return valid;
}

int graphics::onXMinTextChanged(const QString &text) {
  int valid = 1;

  static const QRegularExpression regex("^[-]?[0-9]{1,7}(\\.[0-9]{1,3})?$");
  QRegularExpressionMatch match = regex.match(text);

  if (text.length() == 0) {
    ui->x_beg->setStyleSheet(wrong_style);
    ui->x_beg->setPlaceholderText("Enter value");
  } else if (match.hasMatch() && qFabs(text.toDouble()) <= 1000000 &&
             !(text[0] == '0' && text[1] != '.')) {
    ui->x_beg->setStyleSheet(correct_style);
    valid = 0;
  } else {
    ui->x_beg->setStyleSheet(wrong_style);
  }

  return valid;
}

int graphics::onXMaxTextChanged(const QString &text) {
  int valid = 1;

  static const QRegularExpression regex("^[-]?[0-9]{1,7}(\\.[0-9]{1,3})?$");
  QRegularExpressionMatch match = regex.match(text);

  if (text.length() == 0) {
    ui->x_end->setStyleSheet(wrong_style);
    ui->x_end->setPlaceholderText("Enter value");
  } else if (match.hasMatch() && qFabs(text.toDouble()) <= 1000000 &&
             !(text[0] == '0' && text[1] != '.')) {
    ui->x_end->setStyleSheet(correct_style);
    valid = 0;
  } else {
    ui->x_end->setStyleSheet(wrong_style);
  }

  return valid;
}

int graphics::onYMinTextChanged(const QString &text) {
  int valid = 1;

  static const QRegularExpression regex("^[-]?[0-9]{1,7}(\\.[0-9]{1,3})?$");
  QRegularExpressionMatch match = regex.match(text);

  if (text.length() == 0) {
    ui->y_beg->setStyleSheet(wrong_style);
    ui->y_beg->setPlaceholderText("Enter value");
  } else if (match.hasMatch() && qFabs(text.toDouble()) <= 1000000 &&
             !(text[0] == '0' && text[1] != '.')) {
    ui->y_beg->setStyleSheet(correct_style);
    valid = 0;
  } else {
    ui->y_beg->setStyleSheet(wrong_style);
  }

  return valid;
}

int graphics::onYMaxTextChanged(const QString &text) {
  int valid = 1;

  static const QRegularExpression regex("^[-]?[0-9]{1,7}(\\.[0-9]{1,3})?$");
  QRegularExpressionMatch match = regex.match(text);

  if (text.length() == 0) {
    ui->y_end->setStyleSheet(wrong_style);
    ui->y_end->setPlaceholderText("Enter value");
  } else if (match.hasMatch() && qFabs(text.toDouble()) <= 1000000 &&
             !(text[0] == '0' && text[1] != '.')) {
    ui->y_end->setStyleSheet(correct_style);
    valid = 0;
  } else {
    ui->y_end->setStyleSheet(wrong_style);
  }

  return valid;
}

int graphics::check_symbol(QString expression, QChar first, QChar second) {
  int count_first = 0;
  int count_second = 0;

  for (int i = 0; i < expression.length(); i++) {
    if (expression[i] == first) {
      count_first++;
    } else if (expression[i] == second) {
      count_second++;
    }
  }

  return (count_first != count_second) ? YES : NO;
}

void graphics::onMouseWheel() {
  QCPRange xRange = ui->Table->xAxis->range();
  QCPRange yRange = ui->Table->yAxis->range();

  if (ui->Table->graphCount() > 0) {
    if (yRange.size() > yEnd - yBegin || xRange.size() > xEnd - xBegin) {
      ui->Table->xAxis->setRange(current_x_min, current_x_max);
      ui->Table->yAxis->setRange(current_y_min, current_y_max);
    } else if (xRange.size() < 8 || yRange.size() < 8) {
      ui->Table->xAxis->setRange(current_x_min, current_x_max);
      ui->Table->yAxis->setRange(current_y_min, current_y_max);
    }
  }
  current_x_min = ui->Table->xAxis->range().lower;
  current_x_max = ui->Table->xAxis->range().upper;
  current_y_min = ui->Table->yAxis->range().lower;
  current_y_max = ui->Table->yAxis->range().upper;
}

void graphics::slotMousePress(QMouseEvent *event) {
  if (tracer && ((last_step != ui->step->text().toDouble() &&
                  ui->step->text().toDouble() != 0) ||
                 tracer_visible)) {
    tracer = nullptr;
    tracer = new QCPItemTracer(ui->Table);
    tracer->setGraph(ui->Table->graph(0));
    tracer->setVisible(ui->x_trace->isVisible());
    tracer_visible = 0;
  }
  if (tracer && ui->x_trace->isVisible()) {
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

void graphics::slotMouseMove(QMouseEvent *event) {
  if (tracer && ui->x_trace->isVisible()) {
    if (QApplication::mouseButtons()) slotMousePress(event);
  }
}

void graphics::build_plot(QString expression) {
  if (ui->step->text().toDouble() != 0 &&
      (ui->x_end->text().toDouble() - ui->x_beg->text().toDouble() >= 4 &&
       ui->y_end->text().toDouble() - ui->y_beg->text().toDouble() >= 4)) {
    if (tracer && last_expr != expression) {
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

    N = (xEnd - xBegin) / h + 2;

    for (X = xBegin; X <= xEnd; X += h) {
      result = calculate(expression, X);
      diff = fabs(result - prev);
      x.push_back(X);
      if (result < yEnd && result > yBegin && diff < 200) {
        y.push_back(result);
      } else {
        y.push_back(std::nan(""));
      }
      prev = result;
    }

    ui->Table->addGraph(ui->Table->xAxis, ui->Table->yAxis);
    ui->Table->graph(0)->setData(x, y);

    ui->Table->replot();
    if (ui->Table->xAxis->range().size() >= 10 &&
        ui->Table->yAxis->range().size() >= 10) {
      ui->Table->setInteraction(QCP::iRangeZoom, true);
    }
    if (!ui->x_trace->isVisible()) {
      ui->Table->setInteraction(QCP::iRangeDrag, true);
    }
    current_x_min = xBegin;
    current_x_max = xEnd;
    current_y_min = yBegin;
    current_y_max = yEnd;
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
//                 ui->Table->graph(graph_nums)->setData(allX.back(),
//                 allY.back()); graph_nums++; graph_this = 0;
//             }
//         }
//         ui->Table->replot();
//         ui->Table->setInteraction(QCP::iRangeZoom, true);
//         if(!ui->x_trace->isVisible()) {
//             ui->Table->setInteraction(QCP::iRangeDrag, true);
//         }
//     }
// }

void graphics::on_trace_enable_clicked() {
  if (tracer) {
    if (!tracer_visible) {
      tracer->setVisible(!tracer->visible());
    }
    if (ui->x_trace->isVisible()) {
      ui->trace_enable->setStyleSheet(
          "QPushButton {background-color: rgb(175, 97, 33); border-radius: "
          "10px; } QPushButton:pressed {background-color: rgb(0, 146, 209);}");
      ui->Table->setInteraction(QCP::iRangeDrag, true);
      change_label_visible(false);
    } else {
      ui->trace_enable->setStyleSheet(
          "QPushButton {background-color: rgb(0, 146, 209); border-radius: "
          "10px; } QPushButton:pressed {background-color: rgb(175, 97, 33);}");
      ui->Table->setInteraction(QCP::iRangeDrag, false);
      change_label_visible(true);
    }
  } else {
    if (ui->Table->graphCount() > 0) {
      tracer = new QCPItemTracer(ui->Table);
      tracer->setGraph(ui->Table->graph(0));
      ui->trace_enable->setStyleSheet(
          "QPushButton {background-color: rgb(0, 146, 209); border-radius: "
          "10px; } QPushButton:pressed {background-color: rgb(175, 97, 33);}");
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
