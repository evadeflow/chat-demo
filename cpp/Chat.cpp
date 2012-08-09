#include "Chat.h"
 
Chat::Chat(QObject* parent) :
        QObject(parent)
{
}
 
Chat::~Chat()
{
}
 
void Chat::addUser(QString const& user)
{
    if (!m_users.contains(user))
    {
        m_users.append(user);
 
        emit userAdded(user);
    }
}
 
void Chat::removeUser(QString const& user)
{
    if (m_users.contains(user))
    {
        m_users.removeOne(user);
 
        emit userRemoved(user);
    }
}
 
void Chat::sendMessage(Message const& message)
{
    Q_EMIT messageSent(message);
}
 
QStringList Chat::users() const
{
    return m_users;
}
