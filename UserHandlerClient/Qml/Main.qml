import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import UI.Main 1.0
Window
{
    visible: true
    width: 400
    height: 400

    ColumnLayout
    {
        anchors.centerIn: parent
        component LabelInfo: RowLayout
        {
            id: container
            required property string label
            required property string info
            width: 400
            height: 100
            Text
            {
                Layout.alignment: Qt.AlignVCenter
                text: container.label
                font{
                    family: "Roboto"
                    pixelSize: 14
                }
            }
            Text
            {
                Layout.alignment: Qt.AlignVCenter
                Layout.fillWidth: true
                text: container.info
                horizontalAlignment: Text.AlignHCenter 
                font{
                    family: "Roboto"
                    pixelSize: 14
                }
            }
        }
        LabelInfo
        {
            label: "Press"
            info: controller.pressCount
        }
        LabelInfo
        {
            label: "Time"
            info: controller.pressDateTime
        }

    }

}
