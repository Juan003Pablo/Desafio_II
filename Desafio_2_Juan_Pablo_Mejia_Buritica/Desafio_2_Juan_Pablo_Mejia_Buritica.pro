TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Funciones.cpp \
        Menus.cpp \
        alojamiento.cpp \
        anfitrion.cpp \
        fecha.cpp \
        huesped.cpp \
        main.cpp \
        reservacion.cpp

HEADERS += \
    Funciones.h \
    alojamiento.h \
    anfitrion.h \
    fecha.h \
    huesped.h \
    reservacion.h

DISTFILES += \
    .gitignore
