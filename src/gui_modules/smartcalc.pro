QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/include

SOURCES += \
    ./cpp_modules/graphics.cpp \
    ./cpp_modules/main.cpp \
    ./cpp_modules/my_widget.cpp \
    ./cpp_modules/qcustomplot.cpp \
    ./cpp_modules/credit.cpp \
    ./cpp_modules/credit_table.cpp \
    ./cpp_modules/deposit.cpp \
    ./cpp_modules/smartcalc.cpp

HEADERS += \
    ./include/graphics.h \
    ./include/my_widget.h \
    ./include/qcustomplot.h \
    ./include/credit.h \
    ./include/credit_table.h \
    ./include/deposit.h \
    ./include/smartcalc.h

FORMS += \
    ./ui_modules/graphics.ui \
    ./ui_modules/my_widget.ui \
    ./ui_modules/credit.ui \
    ./ui_modules/credit_table.ui \
    ./ui_modules/deposit.ui \
    ./ui_modules/smartcalc.ui

LIBS += ./../smartcalc.a

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ./../resources/resource.qrc
