# -------------------------------------------------
# Project created by QtCreator 2010-04-06T21:08:22
# -------------------------------------------------
QT += dbus
CONFIG += debug
TARGET = DBusChat
TEMPLATE = app
SOURCES += main.cpp \
    ChatWindow.cpp \
    Chat.cpp \
    Message.cpp \
    ChatAdaptor.cpp \
    ChatInterface.cpp
HEADERS += ChatWindow.h \
    Chat.h \
    Message.h \
    ChatAdaptor.h \
    ChatInterface.h
FORMS += ../ui/ChatWindow.ui

