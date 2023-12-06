#include "graphics.h"
#include "ui_graphics.h"

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
