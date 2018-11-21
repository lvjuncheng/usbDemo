TEMPLATE = app

QT += qml quick

SOURCES += main.cpp \
    usb.cpp \
    usbhandle.cpp

RESOURCES += qml.qrc

INCLUDEPATH +=$$PWD/3rd/include
LIBS += -L$$PWD/3rd/lib -llibusb


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

HEADERS += \
    usb.h \
    usbhandle.h
