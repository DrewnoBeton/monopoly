TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        funkcje.cpp \
        gracz.cpp \
        main.cpp \
        menu.cpp \
        pole.cpp

HEADERS += \
        gracz.h \
        menu.h \
        monopoly.h \
        pole.h

INCLUDEPATH += "D:\polibuda\sfml\SFML-2.5.1\include"
LIBS += -L"D:\polibuda\sfml\SFML-2.5.1\lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

