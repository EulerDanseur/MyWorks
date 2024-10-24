QT       += core gui
QT += webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Start.cpp \
    book.cpp \
    icon.cpp \
    learn.cpp \
    main.cpp \
    mytitlebar.cpp

HEADERS += \
    Start.h \
    animationeffect.h \
    book.h \
    icon.h \
    learn.h

FORMS += \
    Start.ui \
    learn.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc

DISTFILES +=

