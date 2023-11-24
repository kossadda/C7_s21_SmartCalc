/********************************************************************************
** Form generated from reading UI file 'smartcalc.ui'
**
** Created by: Qt User Interface Compiler version 5.15.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMARTCALC_H
#define UI_SMARTCALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_smartcalc
{
public:
    QWidget *centralwidget;
    QPushButton *push_erase;
    QPushButton *push_acos;
    QPushButton *push_pl_min;
    QPushButton *push_1;
    QPushButton *push_4;
    QPushButton *push_square;
    QPushButton *push_eq;
    QPushButton *push_tan;
    QPushButton *push_sqrt;
    QPushButton *push_bkt2;
    QPushButton *push_exp;
    QPushButton *push_sub_unar;
    QPushButton *push_CE;
    QPushButton *push_6;
    QPushButton *push_sum;
    QPushButton *push_expon;
    QPushButton *push_inverse;
    QPushButton *push_cos;
    QPushButton *push_mod;
    QPushButton *push_C;
    QPushButton *push_ln;
    QPushButton *push_sin;
    QPushButton *push_mult;
    QLineEdit *resfield;
    QPushButton *push_9;
    QPushButton *push_8;
    QPushButton *push_2;
    QPushButton *push_atan;
    QPushButton *push_perc;
    QPushButton *push_log;
    QPushButton *push_0;
    QPushButton *push_asin;
    QPushButton *push_3;
    QPushButton *push_sub;
    QPushButton *push_bkt1;
    QPushButton *push_dot;
    QPushButton *push_pi;
    QPushButton *push_7;
    QPushButton *push_sum_unar;
    QPushButton *push_5;
    QPushButton *push_div;
    QLineEdit *history;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *smartcalc)
    {
        if (smartcalc->objectName().isEmpty())
            smartcalc->setObjectName(QString::fromUtf8("smartcalc"));
        smartcalc->resize(680, 580);
        smartcalc->setAutoFillBackground(true);
        centralwidget = new QWidget(smartcalc);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        push_erase = new QPushButton(centralwidget);
        push_erase->setObjectName(QString::fromUtf8("push_erase"));
        push_erase->setGeometry(QRect(568, 94, 80, 70));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        push_erase->setFont(font);
        push_erase->setStyleSheet(QString::fromUtf8(" QPushButton#push_erase {\n"
"     background-color: rgba(65, 79, 92, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_erase:pressed {\n"
"     background-color: rgb(42, 78, 92);\n"
"     border-style: inset;\n"
" }"));
        push_acos = new QPushButton(centralwidget);
        push_acos->setObjectName(QString::fromUtf8("push_acos"));
        push_acos->setGeometry(QRect(250, 200, 80, 70));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setStrikeOut(false);
        push_acos->setFont(font1);
        push_acos->setStyleSheet(QString::fromUtf8(" QPushButton#push_acos {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_acos:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_pl_min = new QPushButton(centralwidget);
        push_pl_min->setObjectName(QString::fromUtf8("push_pl_min"));
        push_pl_min->setGeometry(QRect(351, 480, 80, 70));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(false);
        push_pl_min->setFont(font2);
        push_pl_min->setStyleSheet(QString::fromUtf8(" QPushButton#push_pl_min {\n"
"     background-color: rgba(48, 59, 68, 0.8);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     font: bold 25px;\n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_pl_min:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_1 = new QPushButton(centralwidget);
        push_1->setObjectName(QString::fromUtf8("push_1"));
        push_1->setGeometry(QRect(351, 410, 80, 70));
        push_1->setFont(font2);
        push_1->setStyleSheet(QString::fromUtf8(" QPushButton#push_1 {\n"
"     background-color: rgba(48, 59, 68, 0.8);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     font: bold 25px;\n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_1:pressed {\n"
"     background-color: rgb(42, 78, 92);\n"
"     border-style: inset;\n"
" }"));
        push_4 = new QPushButton(centralwidget);
        push_4->setObjectName(QString::fromUtf8("push_4"));
        push_4->setGeometry(QRect(351, 340, 80, 70));
        push_4->setFont(font2);
        push_4->setStyleSheet(QString::fromUtf8(" QPushButton#push_4 {\n"
"     background-color: rgba(48, 59, 68, 0.8);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     font: bold 25px;\n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_4:pressed {\n"
"     background-color: rgb(42, 78, 92);\n"
"     border-style: inset;\n"
" }"));
        push_square = new QPushButton(centralwidget);
        push_square->setObjectName(QString::fromUtf8("push_square"));
        push_square->setGeometry(QRect(250, 480, 80, 70));
        push_square->setFont(font1);
        push_square->setStyleSheet(QString::fromUtf8(" QPushButton#push_square {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_square:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_eq = new QPushButton(centralwidget);
        push_eq->setObjectName(QString::fromUtf8("push_eq"));
        push_eq->setGeometry(QRect(590, 410, 80, 140));
        push_eq->setFont(font2);
        push_eq->setStyleSheet(QString::fromUtf8(" QPushButton#push_eq {\n"
"     background-color: rgba(233, 116, 36, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     font: bold 25px;\n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_eq:pressed {\n"
"     background-color: rgb(20, 52, 65);\n"
"     border-style: inset;\n"
" }"));
        push_tan = new QPushButton(centralwidget);
        push_tan->setObjectName(QString::fromUtf8("push_tan"));
        push_tan->setGeometry(QRect(170, 340, 80, 70));
        push_tan->setFont(font1);
        push_tan->setStyleSheet(QString::fromUtf8(" QPushButton#push_tan {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_tan:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_sqrt = new QPushButton(centralwidget);
        push_sqrt->setObjectName(QString::fromUtf8("push_sqrt"));
        push_sqrt->setGeometry(QRect(170, 480, 80, 70));
        push_sqrt->setFont(font1);
        push_sqrt->setStyleSheet(QString::fromUtf8(" QPushButton#push_sqrt {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_sqrt:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_bkt2 = new QPushButton(centralwidget);
        push_bkt2->setObjectName(QString::fromUtf8("push_bkt2"));
        push_bkt2->setGeometry(QRect(90, 200, 80, 70));
        push_bkt2->setFont(font1);
        push_bkt2->setStyleSheet(QString::fromUtf8(" QPushButton#push_bkt2 {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_bkt2:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_exp = new QPushButton(centralwidget);
        push_exp->setObjectName(QString::fromUtf8("push_exp"));
        push_exp->setGeometry(QRect(90, 480, 80, 70));
        push_exp->setFont(font1);
        push_exp->setStyleSheet(QString::fromUtf8(" QPushButton#push_exp {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_exp:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_sub_unar = new QPushButton(centralwidget);
        push_sub_unar->setObjectName(QString::fromUtf8("push_sub_unar"));
        push_sub_unar->setGeometry(QRect(90, 340, 80, 70));
        push_sub_unar->setFont(font1);
        push_sub_unar->setStyleSheet(QString::fromUtf8(" QPushButton#push_sub_unar {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_sub_unar:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_CE = new QPushButton(centralwidget);
        push_CE->setObjectName(QString::fromUtf8("push_CE"));
        push_CE->setGeometry(QRect(351, 200, 80, 70));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setStrikeOut(false);
        push_CE->setFont(font3);
        push_CE->setStyleSheet(QString::fromUtf8(" QPushButton#push_CE {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_CE:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_6 = new QPushButton(centralwidget);
        push_6->setObjectName(QString::fromUtf8("push_6"));
        push_6->setGeometry(QRect(510, 340, 80, 70));
        push_6->setFont(font2);
        push_6->setStyleSheet(QString::fromUtf8(" QPushButton#push_6 {\n"
"     background-color: rgba(48, 59, 68, 0.8);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     font: bold 25px;\n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_6:pressed {\n"
"     background-color: rgb(42, 78, 92);\n"
"     border-style: inset;\n"
" }"));
        push_sum = new QPushButton(centralwidget);
        push_sum->setObjectName(QString::fromUtf8("push_sum"));
        push_sum->setGeometry(QRect(590, 340, 80, 70));
        QFont font4;
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setStrikeOut(false);
        push_sum->setFont(font4);
        push_sum->setStyleSheet(QString::fromUtf8(" QPushButton#push_sum {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_sum:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_expon = new QPushButton(centralwidget);
        push_expon->setObjectName(QString::fromUtf8("push_expon"));
        push_expon->setGeometry(QRect(10, 270, 80, 70));
        push_expon->setFont(font1);
        push_expon->setStyleSheet(QString::fromUtf8(" QPushButton#push_expon {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_expon:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_inverse = new QPushButton(centralwidget);
        push_inverse->setObjectName(QString::fromUtf8("push_inverse"));
        push_inverse->setGeometry(QRect(250, 410, 80, 70));
        push_inverse->setFont(font1);
        push_inverse->setStyleSheet(QString::fromUtf8(" QPushButton#push_inverse {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_inverse:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_cos = new QPushButton(centralwidget);
        push_cos->setObjectName(QString::fromUtf8("push_cos"));
        push_cos->setGeometry(QRect(170, 200, 80, 70));
        push_cos->setFont(font1);
        push_cos->setStyleSheet(QString::fromUtf8(" QPushButton#push_cos {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_cos:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_mod = new QPushButton(centralwidget);
        push_mod->setObjectName(QString::fromUtf8("push_mod"));
        push_mod->setGeometry(QRect(90, 270, 80, 70));
        push_mod->setFont(font1);
        push_mod->setStyleSheet(QString::fromUtf8(" QPushButton#push_mod {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_mod:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_C = new QPushButton(centralwidget);
        push_C->setObjectName(QString::fromUtf8("push_C"));
        push_C->setGeometry(QRect(430, 200, 80, 70));
        push_C->setFont(font3);
        push_C->setStyleSheet(QString::fromUtf8(" QPushButton#push_C {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_C:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_ln = new QPushButton(centralwidget);
        push_ln->setObjectName(QString::fromUtf8("push_ln"));
        push_ln->setGeometry(QRect(10, 410, 80, 70));
        push_ln->setFont(font1);
        push_ln->setStyleSheet(QString::fromUtf8(" QPushButton#push_ln {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_ln:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_sin = new QPushButton(centralwidget);
        push_sin->setObjectName(QString::fromUtf8("push_sin"));
        push_sin->setGeometry(QRect(170, 270, 80, 70));
        push_sin->setFont(font1);
        push_sin->setStyleSheet(QString::fromUtf8(" QPushButton#push_sin {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_sin:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_mult = new QPushButton(centralwidget);
        push_mult->setObjectName(QString::fromUtf8("push_mult"));
        push_mult->setGeometry(QRect(590, 200, 80, 70));
        QFont font5;
        font5.setPointSize(13);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setStrikeOut(false);
        push_mult->setFont(font5);
        push_mult->setStyleSheet(QString::fromUtf8(" QPushButton#push_mult {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_mult:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        resfield = new QLineEdit(centralwidget);
        resfield->setObjectName(QString::fromUtf8("resfield"));
        resfield->setGeometry(QRect(10, 70, 660, 111));
        QFont font6;
        font6.setPointSize(29);
        font6.setBold(false);
        font6.setItalic(false);
        font6.setStrikeOut(false);
        resfield->setFont(font6);
        resfield->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid rgba(42, 78, 92, 0.9); \n"
"    border-style: double;\n"
"    padding: 5px;\n"
"    text-align: right;\n"
"}\n"
""));
        push_9 = new QPushButton(centralwidget);
        push_9->setObjectName(QString::fromUtf8("push_9"));
        push_9->setGeometry(QRect(510, 270, 80, 70));
        push_9->setFont(font2);
        push_9->setStyleSheet(QString::fromUtf8(" QPushButton#push_9 {\n"
"     background-color: rgba(48, 59, 68, 0.8);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     font: bold 25px;\n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_9:pressed {\n"
"     background-color: rgb(42, 78, 92);\n"
"     border-style: inset;\n"
" }"));
        push_8 = new QPushButton(centralwidget);
        push_8->setObjectName(QString::fromUtf8("push_8"));
        push_8->setGeometry(QRect(430, 270, 80, 70));
        push_8->setFont(font2);
        push_8->setStyleSheet(QString::fromUtf8(" QPushButton#push_8 {\n"
"     background-color: rgba(48, 59, 68, 0.8);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     font: bold 25px;\n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_8:pressed {\n"
"     background-color: rgb(42, 78, 92);\n"
"     border-style: inset;\n"
" }"));
        push_2 = new QPushButton(centralwidget);
        push_2->setObjectName(QString::fromUtf8("push_2"));
        push_2->setGeometry(QRect(430, 410, 80, 70));
        push_2->setFont(font2);
        push_2->setStyleSheet(QString::fromUtf8(" QPushButton#push_2 {\n"
"     background-color: rgba(48, 59, 68, 0.8);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     font: bold 25px;\n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_2:pressed {\n"
"     background-color: rgb(42, 78, 92);\n"
"     border-style: inset;\n"
" }"));
        push_atan = new QPushButton(centralwidget);
        push_atan->setObjectName(QString::fromUtf8("push_atan"));
        push_atan->setGeometry(QRect(250, 340, 80, 70));
        push_atan->setFont(font1);
        push_atan->setStyleSheet(QString::fromUtf8(" QPushButton#push_atan {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_atan:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_perc = new QPushButton(centralwidget);
        push_perc->setObjectName(QString::fromUtf8("push_perc"));
        push_perc->setGeometry(QRect(170, 410, 80, 70));
        push_perc->setFont(font3);
        push_perc->setStyleSheet(QString::fromUtf8(" QPushButton#push_perc {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_perc:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_log = new QPushButton(centralwidget);
        push_log->setObjectName(QString::fromUtf8("push_log"));
        push_log->setGeometry(QRect(90, 410, 80, 70));
        push_log->setFont(font1);
        push_log->setStyleSheet(QString::fromUtf8(" QPushButton#push_log {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_log:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_0 = new QPushButton(centralwidget);
        push_0->setObjectName(QString::fromUtf8("push_0"));
        push_0->setGeometry(QRect(430, 480, 80, 70));
        push_0->setFont(font2);
        push_0->setStyleSheet(QString::fromUtf8(" QPushButton#push_0 {\n"
"     background-color: rgba(48, 59, 68, 0.8);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     font: bold 25px;\n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_0:pressed {\n"
"     background-color: rgb(42, 78, 92);\n"
"     border-style: inset;\n"
" }"));
        push_asin = new QPushButton(centralwidget);
        push_asin->setObjectName(QString::fromUtf8("push_asin"));
        push_asin->setGeometry(QRect(250, 270, 80, 70));
        push_asin->setFont(font1);
        push_asin->setStyleSheet(QString::fromUtf8(" QPushButton#push_asin {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_asin:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_3 = new QPushButton(centralwidget);
        push_3->setObjectName(QString::fromUtf8("push_3"));
        push_3->setGeometry(QRect(510, 410, 80, 70));
        push_3->setFont(font2);
        push_3->setStyleSheet(QString::fromUtf8(" QPushButton#push_3 {\n"
"     background-color: rgba(48, 59, 68, 0.8);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     font: bold 25px;\n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_3:pressed {\n"
"     background-color: rgb(42, 78, 92);\n"
"     border-style: inset;\n"
" }"));
        push_sub = new QPushButton(centralwidget);
        push_sub->setObjectName(QString::fromUtf8("push_sub"));
        push_sub->setGeometry(QRect(590, 270, 80, 70));
        QFont font7;
        font7.setPointSize(18);
        font7.setBold(true);
        font7.setItalic(false);
        font7.setStrikeOut(false);
        push_sub->setFont(font7);
        push_sub->setStyleSheet(QString::fromUtf8(" QPushButton#push_sub {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_sub:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_bkt1 = new QPushButton(centralwidget);
        push_bkt1->setObjectName(QString::fromUtf8("push_bkt1"));
        push_bkt1->setGeometry(QRect(10, 200, 80, 70));
        push_bkt1->setFont(font1);
        push_bkt1->setStyleSheet(QString::fromUtf8(" QPushButton#push_bkt1 {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_bkt1:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_dot = new QPushButton(centralwidget);
        push_dot->setObjectName(QString::fromUtf8("push_dot"));
        push_dot->setGeometry(QRect(510, 480, 80, 70));
        push_dot->setFont(font2);
        push_dot->setStyleSheet(QString::fromUtf8(" QPushButton#push_dot {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_dot:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_pi = new QPushButton(centralwidget);
        push_pi->setObjectName(QString::fromUtf8("push_pi"));
        push_pi->setGeometry(QRect(10, 480, 80, 70));
        push_pi->setFont(font1);
        push_pi->setStyleSheet(QString::fromUtf8(" QPushButton#push_pi {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_pi:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_7 = new QPushButton(centralwidget);
        push_7->setObjectName(QString::fromUtf8("push_7"));
        push_7->setGeometry(QRect(351, 270, 80, 70));
        push_7->setFont(font2);
        push_7->setStyleSheet(QString::fromUtf8(" QPushButton#push_7 {\n"
"     background-color: rgba(48, 59, 68, 0.8);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     font: bold 25px;\n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_7:pressed {\n"
"     background-color: rgb(42, 78, 92);\n"
"     border-style: inset;\n"
" }"));
        push_sum_unar = new QPushButton(centralwidget);
        push_sum_unar->setObjectName(QString::fromUtf8("push_sum_unar"));
        push_sum_unar->setGeometry(QRect(10, 340, 80, 70));
        push_sum_unar->setFont(font1);
        push_sum_unar->setStyleSheet(QString::fromUtf8(" QPushButton#push_sum_unar {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_sum_unar:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        push_5 = new QPushButton(centralwidget);
        push_5->setObjectName(QString::fromUtf8("push_5"));
        push_5->setGeometry(QRect(430, 340, 80, 70));
        push_5->setFont(font2);
        push_5->setStyleSheet(QString::fromUtf8(" QPushButton#push_5 {\n"
"     background-color: rgba(48, 59, 68, 0.8);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     font: bold 25px;\n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_5:pressed {\n"
"     background-color: rgb(42, 78, 92);\n"
"     border-style: inset;\n"
" }"));
        push_div = new QPushButton(centralwidget);
        push_div->setObjectName(QString::fromUtf8("push_div"));
        push_div->setGeometry(QRect(510, 200, 80, 70));
        QFont font8;
        font8.setPointSize(23);
        font8.setBold(false);
        font8.setItalic(false);
        font8.setStrikeOut(false);
        push_div->setFont(font8);
        push_div->setStyleSheet(QString::fromUtf8(" QPushButton#push_div {\n"
"     background-color: rgba(20, 52, 65, 0.7);\n"
"     border-style: double;\n"
"     border-width: 3px;\n"
"     border-color: rgba(42, 78, 92, 0.9); \n"
"     min-width: 2em;\n"
"     padding: 1px;\n"
"	 color: rgba(255, 255, 255, 0.8);\n"
" }\n"
" QPushButton#push_div:pressed {\n"
"     background-color: rgb(108, 63, 0);\n"
"     border-style: inset;\n"
" }"));
        history = new QLineEdit(centralwidget);
        history->setObjectName(QString::fromUtf8("history"));
        history->setGeometry(QRect(10, 10, 660, 61));
        QFont font9;
        font9.setPointSize(17);
        history->setFont(font9);
        history->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid rgba(42, 78, 92, 0.9); \n"
"    border-style: double;\n"
"    padding: 5px;\n"
"    text-align: right;\n"
"}\n"
""));
        smartcalc->setCentralWidget(centralwidget);
        push_acos->raise();
        push_pl_min->raise();
        push_1->raise();
        push_4->raise();
        push_square->raise();
        push_eq->raise();
        push_tan->raise();
        push_sqrt->raise();
        push_bkt2->raise();
        push_exp->raise();
        push_sub_unar->raise();
        push_CE->raise();
        push_6->raise();
        push_sum->raise();
        push_expon->raise();
        push_inverse->raise();
        push_cos->raise();
        push_mod->raise();
        push_C->raise();
        push_ln->raise();
        push_sin->raise();
        push_mult->raise();
        resfield->raise();
        push_9->raise();
        push_8->raise();
        push_2->raise();
        push_atan->raise();
        push_perc->raise();
        push_log->raise();
        push_0->raise();
        push_asin->raise();
        push_3->raise();
        push_sub->raise();
        push_bkt1->raise();
        push_dot->raise();
        push_pi->raise();
        push_7->raise();
        push_sum_unar->raise();
        push_5->raise();
        push_div->raise();
        push_erase->raise();
        history->raise();
        menubar = new QMenuBar(smartcalc);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 680, 23));
        smartcalc->setMenuBar(menubar);
        statusbar = new QStatusBar(smartcalc);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        smartcalc->setStatusBar(statusbar);

        retranslateUi(smartcalc);

        QMetaObject::connectSlotsByName(smartcalc);
    } // setupUi

    void retranslateUi(QMainWindow *smartcalc)
    {
        smartcalc->setWindowTitle(QCoreApplication::translate("smartcalc", "smartcalc", nullptr));
        push_erase->setText(QCoreApplication::translate("smartcalc", "\342\214\253", nullptr));
        push_acos->setText(QCoreApplication::translate("smartcalc", "acos", nullptr));
        push_pl_min->setText(QCoreApplication::translate("smartcalc", "+/-", nullptr));
        push_1->setText(QCoreApplication::translate("smartcalc", "1", nullptr));
        push_4->setText(QCoreApplication::translate("smartcalc", "4", nullptr));
        push_square->setText(QCoreApplication::translate("smartcalc", " x\302\262", nullptr));
        push_eq->setText(QCoreApplication::translate("smartcalc", "=", nullptr));
        push_tan->setText(QCoreApplication::translate("smartcalc", "tan", nullptr));
        push_sqrt->setText(QCoreApplication::translate("smartcalc", "\342\210\232x ", nullptr));
        push_bkt2->setText(QCoreApplication::translate("smartcalc", ")", nullptr));
        push_exp->setText(QCoreApplication::translate("smartcalc", "e", nullptr));
        push_sub_unar->setText(QCoreApplication::translate("smartcalc", "-a", nullptr));
        push_CE->setText(QCoreApplication::translate("smartcalc", "CE", nullptr));
        push_6->setText(QCoreApplication::translate("smartcalc", "6", nullptr));
        push_sum->setText(QCoreApplication::translate("smartcalc", "+", nullptr));
        push_expon->setText(QCoreApplication::translate("smartcalc", "x\341\265\236", nullptr));
        push_inverse->setText(QCoreApplication::translate("smartcalc", "1/x", nullptr));
        push_cos->setText(QCoreApplication::translate("smartcalc", "cos", nullptr));
        push_mod->setText(QCoreApplication::translate("smartcalc", "mod", nullptr));
        push_C->setText(QCoreApplication::translate("smartcalc", "C", nullptr));
        push_ln->setText(QCoreApplication::translate("smartcalc", "ln", nullptr));
        push_sin->setText(QCoreApplication::translate("smartcalc", "sin", nullptr));
        push_mult->setText(QCoreApplication::translate("smartcalc", "x", nullptr));
        resfield->setText(QString());
        push_9->setText(QCoreApplication::translate("smartcalc", "9", nullptr));
        push_8->setText(QCoreApplication::translate("smartcalc", "8", nullptr));
        push_2->setText(QCoreApplication::translate("smartcalc", "2", nullptr));
        push_atan->setText(QCoreApplication::translate("smartcalc", "atan", nullptr));
        push_perc->setText(QCoreApplication::translate("smartcalc", "%", nullptr));
        push_log->setText(QCoreApplication::translate("smartcalc", "log", nullptr));
        push_0->setText(QCoreApplication::translate("smartcalc", "0", nullptr));
        push_asin->setText(QCoreApplication::translate("smartcalc", "asin", nullptr));
        push_3->setText(QCoreApplication::translate("smartcalc", "3", nullptr));
        push_sub->setText(QCoreApplication::translate("smartcalc", "-", nullptr));
        push_bkt1->setText(QCoreApplication::translate("smartcalc", "(", nullptr));
        push_dot->setText(QCoreApplication::translate("smartcalc", ".", nullptr));
        push_pi->setText(QCoreApplication::translate("smartcalc", "\317\200", nullptr));
        push_7->setText(QCoreApplication::translate("smartcalc", "7", nullptr));
        push_sum_unar->setText(QCoreApplication::translate("smartcalc", "+a", nullptr));
        push_5->setText(QCoreApplication::translate("smartcalc", "5", nullptr));
        push_div->setText(QCoreApplication::translate("smartcalc", "\303\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class smartcalc: public Ui_smartcalc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTCALC_H
