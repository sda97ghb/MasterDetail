#ifndef USERVIEWMODEL_H
#define USERVIEWMODEL_H

#include <QObject>

class UserViewModel : public QObject {
    Q_OBJECT
public:
    explicit UserViewModel(QObject *parent = nullptr);

signals:

public slots:

private:
//    User m_user;
};

#endif // USERVIEWMODEL_H
