#include "Controller.h"
#include <QDebug>

Controller::Controller()
{
    // if (m_userInfo.isInitialized())
    // qDebug() << "The replicate is Initialized " << m_userInfo.isInitialized();
    qWarning() << "Construct herere";
    UserHandlerReplica a;
    qWarning() << "Construct herere 2222";
}

Controller::~Controller()
{

}
void Controller::accquire(UserHandlerReplica* replica)
{
    m_userInfo.reset(std::move(replica));
    QObject::connect(m_userInfo.get(), &UserHandlerReplica::initialized, this, [this](){
        qDebug() << "The remote object connection has been initialized";
    });
    QObject::connect(m_userInfo.get(), &UserHandlerReplica::userHandlerChanged, this, &Controller::onUserPressChanged);
}

int Controller::pressCount() const
{
    return m_count;
}
QString Controller::pressDateTime() const
{
    return m_dateTime;
}

void Controller::setCount(int value)
{   
    if (value == m_count)
    {
        return;
    }
    m_count = value;
    emit pressCountChanged();
}

void Controller::setDateTime(QString value)
{
    if (value == m_dateTime)
    {
        return;
    }
    m_dateTime = value;
    emit pressDateTimeChanged();
}


void Controller::onUserPressChanged(UserHandler userInfo)
{
    qWarning() << "Press change herere " << userInfo;
    setCount(userInfo.count());
    setDateTime(userInfo.time().toString("dd.MM.yyyy"));
}
