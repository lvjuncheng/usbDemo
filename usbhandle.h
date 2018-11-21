#ifndef USBHANDLE_H
#define USBHANDLE_H

#include <QObject>
#include "usb.h"

class UsbHandle : public QObject
{
    Q_OBJECT
public:
    explicit UsbHandle(QObject *parent = nullptr);
signals:

public slots:
    void onSendBtnClicked();
    void onReadBtnClicked();
private:
    friend class USB;
    USB *m_dt;
};

#endif // USBHANDLE_H
