QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += multimedia

CONFIG += c++11
INCLUDEPATH += header
INCLUDEPATH += source

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
    choosesize.cpp \
    dialog.cpp \
    form.cpp \
    header/game.cpp \
    source/main.cpp \
    source/mainwindow.cpp

HEADERS += \
    choosesize.h \
    dialog.h \
    form.h \
    header/game.h \
    header/mainwindow.h

FORMS += \
    choosesize.ui \
    dialog.ui \
    form.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    other_file/helppic.qrc \
    weiqi_resource.qrc

DISTFILES += \
    other_file/cover.jpg \
    other_file/timg.jpg
    other_file/gameboard.jpg
    other_file/timg.jpg
    other_file/move_chess.mp3
