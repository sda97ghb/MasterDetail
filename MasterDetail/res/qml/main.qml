import QtQuick 2.11
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Window 2.11

import MyTypes 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    UsersViewModel {
        id: usersViewModel
        onCurrentUserChanged: {
            theLoader.item.model = currentUser
        }
    }

    ColumnLayout {
        anchors.fill: parent

        UsersList {
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height / 2
            usersViewModel: usersViewModel
        }

        Component {
            id: userView

            Item {
                id: root
                property UserViewModel model: null

                Rectangle {
//                    anchors.fill: parent
                    anchors.centerIn: parent
                    width: 400
                    height: 200

                    GridLayout {
                        columns: 2

                        Text { Layout.preferredHeight: 40; Layout.preferredWidth: 100; text: "Firstname:" }
                        Text { Layout.preferredHeight: 40; Layout.preferredWidth: 100; text: root.model.firstName }
                        Text { Layout.preferredHeight: 40; Layout.preferredWidth: 100; text: "Lastname:" }
                        Text { Layout.preferredHeight: 40; Layout.preferredWidth: 100; text: root.model.lastName }
                        Text { Layout.preferredHeight: 40; Layout.preferredWidth: 100; text: "Age:" }
                        Text { Layout.preferredHeight: 40; Layout.preferredWidth: 100; text: root.model.age }
                    }
                }
            }
        }

        Loader {
            id: theLoader
            Layout.fillHeight: true
            sourceComponent: userView
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height / 2
        }
    }
}
