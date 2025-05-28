TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Funciones.cpp \
        alojamiento.cpp \
        anfitrion.cpp \
        fecha.cpp \
        huesped.cpp \
        main.cpp \
        reservacion.cpp \
        sistema_udeastay.cpp

HEADERS += \
    Funciones.h \
    alojamiento.h \
    anfitrion.h \
    fecha.h \
    huesped.h \
    reservacion.h \
    sistema_udeastay.h

DISTFILES += \
    .gitignore
