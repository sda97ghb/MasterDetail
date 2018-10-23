import QtQuick 2.0
import QtQuick.Layouts 1.3

import MyTypes 1.0
import QtQuick.Controls 2.3

Item {
    id: root
    property UserViewModel model: null

    state: root.model ? "userState" : "emptyState"

    GridLayout {
        id: rowLayout
        columns: 2
        anchors.fill: parent

        ColumnLayout {
            Layout.maximumWidth: 250
            Layout.minimumWidth: 250
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.margins: 8

            Text {
                text: qsTr("Firstname")
            }

            TextField {
                id: firstName
                Layout.fillWidth: true
                placeholderText: qsTr("Firstname")
                text: root.model ? root.model.firstName : ""
                onTextChanged: if (root.model) root.model.firstName = firstName.text
            }

            Text {
                text: qsTr("Lastname")
                Layout.topMargin: 16
            }

            TextField {
                id: lastName
                Layout.fillWidth: true
                placeholderText: qsTr("Lastname")
                text: root.model ? root.model.lastName : ""
                onTextChanged: if (root.model) root.model.lastName = lastName.text
            }

            Text {
                text: qsTr("Age")
                Layout.topMargin: 16
            }

            SpinBox {
                id: age
                Layout.fillWidth: true
                value: root.model ? root.model.age : ""
                onValueChanged: if (root.model) root.model.age = age.value
            }

            Button {
                id: button
                text: qsTr("Save")
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.topMargin: 32
                onClicked: if (root.model) root.model.saveUser()
            }
        }

        ListView {
            id: listView
            Layout.fillHeight: true
            Layout.fillWidth: true
            delegate: Item {
                x: 5
                width: 80
                height: 40
                Row {
                    id: row1
                    spacing: 10
                    Rectangle {
                        width: 40
                        height: 40
                        color: colorCode
                    }

                    Text {
                        text: name
                        font.bold: true
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
            }
            model: ListModel {
                ListElement {
                    name: "Grey"
                    colorCode: "grey"
                }

                ListElement {
                    name: "Red"
                    colorCode: "red"
                }

                ListElement {
                    name: "Blue"
                    colorCode: "blue"
                }

                ListElement {
                    name: "Green"
                    colorCode: "green"
                }
            }
        }
    }

    Text {
        id: emptyStateText
        x: 231
        y: 232
        color: "#828282"
        text: qsTr("Select any user from the left list")
        anchors.centerIn: parent
        font.pixelSize: 12
    }
    states: [
        State {
            name: "emptyState"

            PropertyChanges {
                target: rowLayout
                visible: false
            }
        },
        State {
            name: "userState"

            PropertyChanges {
                target: emptyStateText
                visible: false
            }
        }
    ]
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:20;anchors_x:271;anchors_y:130}
}
 ##^##*/
