QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    graphics.cpp \
    main.cpp \
    my_widget.cpp \
    qcustomplot.cpp \
    s21_credit.cpp \
    s21_credit_table.cpp \
    s21_deposit.cpp \
    s21_smartcalc.cpp

HEADERS += \
    graphics.h \
    my_widget.h \
    qcustomplot.h \
    s21_credit.h \
    s21_credit_table.h \
    s21_deposit.h \
    s21_smartcalc.h

FORMS += \
    graphics.ui \
    my_widget.ui \
    s21_credit.ui \
    s21_credit_table.ui \
    s21_deposit.ui \
    s21_smartcalc.ui

LIBS += ./../s21_smartcalc.a

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../s21_pics/resource.qrc
