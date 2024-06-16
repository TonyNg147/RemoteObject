#pragma once
#include <QObject>
#include <UserHandlerRep.h>
#include <QSharedPointer>

class Controller: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int pressCount READ pressCount NOTIFY pressCountChanged)
    Q_PROPERTY(QString pressDateTime READ pressDateTime NOTIFY pressDateTimeChanged)
    public:
        Controller();
        ~Controller();

        int pressCount() const;
        QString pressDateTime() const;

        void accquire(UserHandlerReplica* replica);

    signals:
        void pressCountChanged();
        void pressDateTimeChanged();

    private:
        void onUserPressChanged(UserHandler);

        void setCount(int value);
        void setDateTime(QString);

    private:
        QSharedPointer<UserHandlerReplica> m_userInfo; // save the infor about clicking times and datetime

        int m_count = 0;
        QString m_dateTime = "UNKNOWN";
};
