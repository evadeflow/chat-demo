#include "Message.h"
 
Message::Message() :
        m_user(),
        m_text()
{
}
 
Message::Message(QString const& user, QString const& text) :
        m_user(user),
        m_text(text)
{
}
 
Message::Message(Message const& other) :
        m_user(other.m_user),
        m_text(other.m_text)
{
}
 
Message& Message::operator=(Message const& other)
{
    m_user = other.m_user;
    m_text = other.m_text;
 
    return *this;
}
 
Message::~Message()
{
}
 
QString Message::getUser() const
{
    return m_user;
}
 
QString Message::getText() const
{
    return m_text;
}
 
void Message::registerMetaType()
{
    qRegisterMetaType<Message>("Message");
 
    qDBusRegisterMetaType<Message>();
}
 
QDBusArgument &operator<<(QDBusArgument &argument, Message const& message)
{
    argument.beginStructure();
    argument << message.m_user;
    argument << message.m_text;
    argument.endStructure();
 
    return argument;
}
 
const QDBusArgument &operator>>(QDBusArgument const& argument, Message &message)
{
    argument.beginStructure();
    argument >> message.m_user;
    argument >> message.m_text;
    argument.endStructure();
 
    return argument;
}
