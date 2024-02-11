#ifndef SMARTCALC_H
#define SMARTCALC_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <regex>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QKeyEvent>

#include "./graphics.h"

extern "C" {
#include "./../../modules/smartcalc.h"
}

class credit;
class deposit;

QT_BEGIN_NAMESPACE
namespace Ui {
class smartcalc;
}
QT_END_NAMESPACE

class smartcalc : public QMainWindow
{
    Q_OBJECT

signals:
    void resized(const QSize &newSize);
    void keyPressed(int key);

public:
    smartcalc(QWidget *parent = nullptr);
    ~smartcalc();
    void change_mode(const QString index);
    int valid;
    int font_size;

protected:
    void onCheckExpr(const QString &text);
    void resizeEvent(QResizeEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void handleKeyPress(int key);

private slots:
    int additional_validation(QString text);
    void onResized(const QSize &newSize);
    void on_graphWindowClosed();
    int countDigits(double number);
    void on_actionVarChanged(const QString &text);
    void on_actionVarTriggered();
    void on_actionPlotTriggered();
    void clear_history(int key);
    void save_history();
    void createPlotButton(QPushButton *button, int row);
    void switch_buttons(QString name1, QString name2);
    void change_color(QPushButton *button, QString color);
    void clear_result();
    void add(QString text);
    void push_nums();
    void on_push_eq_clicked();
    void on_push_sqrt_clicked();
    void on_push_log_clicked();
    void on_push_ln_clicked();
    void on_push_sin_clicked();
    void on_push_cos_clicked();
    void on_push_tan_clicked();
    void on_push_asin_clicked();
    void on_push_acos_clicked();
    void on_push_atan_clicked();
    void on_push_mod_clicked();
    void on_push_opn_brack_clicked();
    void on_push_cls_brack_clicked();
    void on_push_div_clicked();
    void on_push_mul_clicked();
    void on_push_sub_clicked();
    void on_push_sum_clicked();
    void on_push_e_clicked();
    void on_push_pi_clicked();
    void on_push_exp_clicked();
    void on_push_c_clicked();
    void on_push_del_clicked();
    void on_push_unar_clicked();
    void on_push_dot_clicked();
    void on_turn_back_clicked();
    void on_move_frwd_clicked();
    void on_graph_clicked();
    void on_variable_clicked();

private:
    Ui::smartcalc *ui;
    QPushButton *pushButton;
    QPushButton *pushButton1;
    QLineEdit *var;
    QStringList history;
    graphics *graphWindow;
    QListWidget* listWidget;
    int correct_var;
    bool clear_after = false;
    int history_count = -1;
};
#endif // SMARTCALC_H
