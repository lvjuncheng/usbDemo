#ifndef USB_H
#define USB_H

#include "lusb0_usb.h"
#include <QObject>

class UsbHandle;
class USB : public QObject
{
    Q_OBJECT
public:
    explicit USB(UsbHandle *pt);
    ~USB();
    usb_dev_handle * open_dev(void);
    void printf_device_descriptor(usb_device_descriptor * desc);
    void read_num();
    void send_num();
    void my_init_usbdev();
private:
    UsbHandle *m_pt;
};

#endif // USB_H
