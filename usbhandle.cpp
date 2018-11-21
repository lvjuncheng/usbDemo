#include "usbhandle.h"
#include <QtDebug>

UsbHandle::UsbHandle(QObject *parent) : QObject(parent)
  ,m_dt(new USB(this))
{

}

void UsbHandle::onSendBtnClicked()
{
    m_dt->send_num();
}

void UsbHandle::onReadBtnClicked()
{
    m_dt->read_num();
}
