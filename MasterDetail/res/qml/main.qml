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
    }

    RowLayout {
        anchors.fill: parent

        UsersList {
            Layout.preferredWidth: 200
            Layout.fillHeight: true
            model: usersViewModel
        }

        UserDetails {
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: usersViewModel.currentUser
        }
    }
}
