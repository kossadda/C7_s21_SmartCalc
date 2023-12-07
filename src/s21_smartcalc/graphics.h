#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>
#include <QCloseEvent>

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

private:
    Ui::graphics *ui;
};

#endif // GRAPHICS_H
