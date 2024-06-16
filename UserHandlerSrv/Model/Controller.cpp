#include "Controller.h"

Controller::Controller()
    :UserHandlerSource()
{
    m_userInfo.setCount(m_currentCount);
}

Controller::~Controller()
{

}

void Controller::onPressed()
{
    m_userInfo.setCount(++m_currentCount);
    m_userInfo.setTime(QDateTime::currentDateTime());
    emit userHandlerChanged(m_userInfo);
}
