import QtQuick 2.11
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

import MyTypes 1.0

Item {
    property UsersViewModel usersViewModel: null

    Component {
        id: userListHeader

        Item {
            id: userListHeaderRoot
            width: ListView.view.width
            height: 32
            z: 2

            Rectangle {
                anchors.fill: parent
                color: "silver"
            }

            RowLayout {
                anchors.fill: parent
                Text {
                    padding: 8
                    Layout.fillHeight: true
                    Layout.preferredWidth: parent.width / 3
                    text: "Firstname"
                    font.bold: true
                }
                Text {
                    padding: 8
                    Layout.fillHeight: true
                    Layout.preferredWidth: parent.width / 3
                    text: "Lastname"
                    font.bold: true
                }
                Text {
                    padding: 8
                    Layout.fillHeight: true
                    Layout.preferredWidth: parent.width / 3
                    text: "Age"
                    font.bold: true
                }
            }
        }
    }

    Component {
        id: usersListDelegate

        Item {
            id: usersListDelegateRoot
            width: ListView.view.width
            height: 32

            RowLayout {
                anchors.fill: parent
                Text {
                    padding: 8
                    Layout.fillHeight: true
                    Layout.preferredWidth: parent.width / 3
                    text: modelData.firstName
                }
                Text {
                    padding: 8
                    Layout.fillHeight: true
                    Layout.preferredWidth: parent.width / 3
                    text: modelData.lastName
                }
                Text {
                    padding: 8
                    Layout.fillHeight: true
                    Layout.preferredWidth: parent.width / 3
                    text: modelData.age
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: usersListDelegateRoot.ListView.view.currentIndex = index
            }
        }
    }

    ListView {
        id: usersListView
        anchors.fill: parent
        model: usersViewModel.users
        delegate: usersListDelegate
        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        highlightMoveDuration: 100
        highlightResizeDuration: 100
        focus: true
        ScrollBar.vertical: ScrollBar {}
        header: userListHeader
        headerPositioning: ListView.PullBackHeader
        onCurrentIndexChanged: usersViewModel.currentUser = usersViewModel.users[currentIndex]
    }
}
