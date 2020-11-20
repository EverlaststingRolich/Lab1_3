QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    money_stack.cpp \
    money_stack_test.cpp \
    ms_window.cpp \
    object.cpp \
    object_collection.cpp \
    object_window.cpp \
    second_window.cpp \
    test.cpp

HEADERS += \
    mainwindow.h \
    money_stack.h \
    ms_window.h \
    object.h \
    object_collection.h \
    object_window.h \
    second_window.h \
    test.h

FORMS += \
    mainwindow.ui \
    ms_window.ui \
    object_window.ui \
    second_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
