QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    s21_additional/graphics.cpp \
    s21_main/main.cpp \
    s21_additional/my_widget.cpp \
    s21_additional/qcustomplot.cpp \
    s21_credit/s21_credit.cpp \
    s21_deposit/s21_deposit.cpp \
    s21_main/s21_smartcalc.cpp

HEADERS += \
    s21_additional/graphics.h \
    s21_additional/my_widget.h \
    s21_additional/qcustomplot.h \
    s21_credit/s21_credit.h \
    s21_deposit/s21_deposit.h \
    s21_main/s21_smartcalc.h

FORMS += \
    s21_additional/graphics.ui \
    s21_additional/my_widget.ui \
    s21_credit/s21_credit.ui \
    s21_deposit/s21_deposit.ui \
    s21_main/s21_smartcalc.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
