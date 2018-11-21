import QtQuick 2.4

Rectangle {
    visible: true
    MainForm {
        readBtn.onClicked: {
            usbHandle.onReadBtnClicked();
        }
        sendBtn.onClicked: {
            usbHandle.onSendBtnClicked();
        }
    }
}
