#pragma once
#include <QObject>
#include <UserHandlerSrc.h>

class Controller: public UserHandlerSource
{
    Q_OBJECT
    public:
        Controller();
        ~Controller();

        virtual UserHandler userHandler() const override
        {
            return m_userInfo;
        }
    public slots:
        void onPressed();

    private:
        UserHandler       m_userInfo; // save the infor about clicking times and datetime
        int               m_currentCount = 0;
};
