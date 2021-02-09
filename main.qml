import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
Item {
    Window {

        id: startWin
        visible: true
        width: 366
        height: 512
        maximumHeight: height
        maximumWidth: width
        minimumHeight: height
        minimumWidth: width
            Image {
            id: fon
            source: "Prot/48.png"

        }

    //////////////////////////////////////////
        Rectangle{
                    id: redd;
            Image {
                id: name;
                source: "Prot/logo.png"
            }
            x:66
            y:31
            width:235
            height:96
                }


    /////////////////////////////////////
        Rectangle{
            x:28
            y:180
            width: 312
            height: 31
            radius:8
            color: "white"
       TextInput{
            id: eT;
            width: 312
            color: "black"
            height: 31
            font.pointSize: 11
        }
           }

    //////////////////////////////////////
        Rectangle{
            x:28
            y:237
            width: 312
            height: 31
            radius:8
            color: "white"

       TextInput{
            id: eTT;
            x: 0
            y: 0
            width: 312
            color: "black"
            height: 31
            font.pointSize: 11

        }

        }
    /////////////////////////////////////
        Rectangle{

        CheckBox{
            id: ffa
            x:27
            y:281
            height:14
            width:13

     }
        }
        Button{
            x:27
            y:321
            height:31
            width:312
            text: "Авторизация"
            objectName: "bInPut"
            signal inPut()
            onClicked: {  inPut();    }



        }


    }
}
