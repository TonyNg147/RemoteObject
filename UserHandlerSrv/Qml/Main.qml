import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import UI.Main 1.0
Window
{
    visible: true
    width: 400
    height: 400

    Button{
        anchors.centerIn: parent
        width: 150
        height: 40
        text:"Click"
        onClicked:{
            controller.onPressed();
        }
    }

}
