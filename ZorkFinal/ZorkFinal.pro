QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    character.cpp \
    command.cpp \
    commandwords.cpp \
    hero.cpp \
    inventory.cpp \
    item.cpp \
    mainwindow.cpp \
    monster.cpp \
    parser.cpp \
    room.cpp

HEADERS += \
    character.h \
    command.h \
    commandwords.h \
    hero.h \
    inventory.h \
    item.h \
    mainwindow.h \
    monster.h \
    parser.h \
    room.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES += \
    Images/beholder.png \
    Images/cave.jpg \
    Images/dungeonstart.jpg \
    Images/playerImage.jpeg \
    Images/prison.jpg
