#include <QGuiApplication>
#include <QQuickView>
#include <QtQml>
#include "lusb0_usb.h"
#include "usb.h"
#include "usbhandle.h"
#define SCREEN_SIZE QSize(1024,600)
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.addLibraryPath(app.applicationDirPath()+"/QtPlugins");
    QQuickView view;
    view.setBaseSize(SCREEN_SIZE);
    view.setMinimumSize(SCREEN_SIZE);
    view.setMaximumSize(SCREEN_SIZE);
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    UsbHandle usbHandle;
    view.rootContext()->setContextProperty("usbHandle",&usbHandle);
    view.setSource(QUrl("qrc:/main.qml"));
    if(!view.rootObject()){
        qCritical()<<"Qml root object is null!";
        return -1;
    }
    view.showNormal();

    return app.exec();
}
