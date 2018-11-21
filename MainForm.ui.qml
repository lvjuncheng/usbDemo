import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0

Rectangle {

    width: 1024
    height: 600
    color: "#ffffff"
    property alias readBtn: readBtn
    property alias sendBtn: sendBtn

    TextArea {
        id: recContext
        x: 48
        y: 46
        width: 908
        height: 381
        color: "#ffffff"
        text: qsTr("")
        font.bold: true
        font.pointSize: 16
    }

    RowLayout {
        x: 48
        y: 479
        width: 908
        height: 40

        Text {
            id: text1
            text: qsTr("发送内容：")
            Layout.preferredHeight: 35
            Layout.preferredWidth: 56
            font.bold: true
            font.pixelSize: 16
        }

        TextEdit {
            id: sendContext
            color: "#ffffff"
            text: qsTr("")
            Layout.preferredHeight: 40
            Layout.preferredWidth: 593
            font.bold: true
            font.pixelSize: 16
        }

        Button {
            id: sendBtn
            text: qsTr("发送")
            font.pointSize: 16
            checkable: false
            checked: false
        }

        Button {
            id: readBtn
            text: qsTr("读取")
            font.pointSize: 16
            checkable: false
            checked: false
        }
    }
}
