TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle qt

SOURCES += \
    Pop/Main.cpp \
    Pop/Visitor.cpp

HEADERS += \
    Pop/AST.hpp \
    Pop/Visitor.hpp \
    Pop/Location.hpp
