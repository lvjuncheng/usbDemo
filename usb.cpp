#include "usb.h"
#include "lusb0_usb.h"
#include <QDebug>

#define MY_VID 0x0525
#define MY_PID 0xa4a5

#define MY_CONFIG 1
#define MY_INTF 0

#define EP_IN 0x81
#define EP_OUT 0x01

#define BUF_SIZE 16

struct usb_device *dev;

struct usb_dev_handle *udev;
char rdata[2];//接收下位机发送的数据22位
char sdata[2];//发送给下位机的数据8位

USB::USB(UsbHandle *pt):
    m_pt(pt)
{
    usb_init();
    usb_find_busses();
    usb_find_devices();

    if(!(udev=open_dev()))
    {
        qDebug("error opening device: %s",usb_strerror());
        exit(1);
    }
    else
        qDebug("open success: device %04X:%04X opened", MY_VID, MY_PID);

    printf_device_descriptor(&dev->descriptor);
    my_init_usbdev();
}

USB::~USB()
{
    usb_close(udev);
}

usb_dev_handle * USB::open_dev(void)
{
    struct usb_bus *bus;

    for(bus=usb_get_busses();bus;bus=bus->next)
    {
        for(dev=bus->devices;dev;dev=dev->next)
        {
            if((dev->descriptor.idVendor==MY_VID)&&(dev->descriptor.idProduct==MY_PID))
            {
                return usb_open(dev);
            }
        }
    }
    return 0;
}

void USB::printf_device_descriptor(usb_device_descriptor * desc)
{
    qDebug("bLength:             %u",     desc->bLength);
    qDebug("bDescriptorType:     %02Xh",  desc->bDescriptorType);
    qDebug("bcdUSB:              %04Xh",  desc->bcdUSB);
    qDebug("bDeviceClass:        %02Xh",  desc->bDeviceClass);
    qDebug("bDeviceSubClass:     %02Xh",  desc->bDeviceSubClass);
    qDebug("bDeviceProtocol:     %02Xh",  desc->bDeviceProtocol);
    qDebug("bMaxPacketSize0:     %02Xh",  desc->bMaxPacketSize0);
    qDebug("idVendor:            %04Xh",  desc->idVendor);
    qDebug("idProduct:           %04Xh",  desc->idProduct);
    qDebug("bcdDevice:           %04Xh",  desc->bcdDevice);
    qDebug("iManufacturer:       %u",     desc->iManufacturer);
    qDebug("iProduct:            %u",     desc->iProduct);
    qDebug("iSerialNumber:       %u",     desc->iSerialNumber);
    qDebug("bNumConfigurations:  %u",     desc->bNumConfigurations);
}

void USB::my_init_usbdev()
{
    if(usb_set_configuration(udev,MY_CONFIG)<0)
    {
        qDebug("error stting config#%d:%s",MY_CONFIG,usb_strerror());
        exit(1);
    }
    if(usb_claim_interface(udev,MY_INTF)<0)
    {
        qDebug("error claiming interface #%d:\n%s",MY_INTF,usb_strerror());
        exit(1);
    }
}

void USB::send_num()
{
    int ret;

    sdata[0]=0x13;
    sdata[1]=1;

    ret=usb_interrupt_write(udev,0x01,sdata,sizeof(sdata),2000);
    qDebug("ret: %d",ret);
    if(ret<0)
    {
        qDebug("ret: %d",ret);
        qDebug("error writing: %s",usb_strerror());
        exit(1);
    }
}

void USB::read_num()
{
    QString str1;
    QString str2;
    QString str3;
    for(int i=0;i<2;i++)
    {
        rdata[i]=0;
     }
    int ret;
    ret=usb_interrupt_read(udev,0x81,rdata,sizeof(rdata),5000);
    if(ret<0){
        qDebug("error reading:%s",usb_strerror());
    }
    qDebug("retr: %d",ret);
    str1=rdata[0];
    qDebug()<<str1;
    str2=rdata[1];
    qDebug()<<str2;
    str3=rdata[2];
    qDebug()<<str3;
    if (rdata[2]=='\0')
    {
        qDebug("sdfsdf");
    }
}
