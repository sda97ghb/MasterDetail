import QtQuick 2.11
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

    Text {
        anchors.fill: parent
        text: usersViewModel.user.data().firstName()
    }

//    ListView {
//        anchors.fill: parent
//        model: ["123", "qwe", "asd", "zxc"]
//        delegate: Text {
//            color: ListView.isCurrentItem ? "red" : "black"
//            text: modelData
//            MouseArea {
//                anchors.fill: parent
//                onClicked: parent.ListView.view.currentIndex = index
//            }
//        }
//        focus: true
//    }

//    // Define a delegate component.  A component will be
//    // instantiated for each visible item in the list.
//    Component {
//        id: petDelegate
//        Item {
//            id: wrapper
//            width: 200; height: 55
//            Column {
//                Text { text: 'Name: ' + name }
//                Text { text: 'Type: ' + type }
//                Text { text: 'Age: ' + age }
//            }
//            // indent the item if it is the current item
//            states: State {
//                name: "Current"
//                when: wrapper.ListView.isCurrentItem
//                PropertyChanges { target: wrapper; x: 20 }
//            }
//            transitions: Transition {
//                NumberAnimation { properties: "x"; duration: 200 }
//            }
//            MouseArea {
//                anchors.fill: parent
//                onClicked: wrapper.ListView.view.currentIndex = index
//            }
//        }
//    }

//    // Define a highlight with customized movement between items.
//    Component {
//        id: highlightBar
//        Rectangle {
//            width: 200; height: 50
//            color: "#FFFF88"
//            y: listView.currentItem.y;
//            Behavior on y { SpringAnimation { spring: 2; damping: 0.1 } }
//        }
//    }

//    ListView {
//        id: listView
//        width: 200; height: parent.height
//        x: 30

//        model: ListModel {
//            ListElement { name: "1"; type: "1"; age: 1 }
//            ListElement { name: "2"; type: "2"; age: 2 }
//            ListElement { name: "3"; type: "3"; age: 3 }
//            ListElement { name: "4"; type: "4"; age: 4 }
//        }

//        delegate: petDelegate
//        focus: true

//        // Set the highlight delegate. Note we must also set highlightFollowsCurrentItem
//        // to false so the highlight delegate can control how the highlight is moved.
//        highlight: highlightBar
//        highlightFollowsCurrentItem: false
//    }
}
