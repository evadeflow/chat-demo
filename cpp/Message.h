#ifndef MESSAGE_H
#define MESSAGE_H
 
#include <QtDBus>
 
class Message
{
public:
    Message();
    Message(QString const& user, QString const& message);
    Message(Message const& other);
    Message& operator=(Message const& other);
    ~Message();
 
    friend QDBusArgument &operator<<(QDBusArgument &argument,
                                     Message const& message);

    friend const QDBusArgument &operator>>(QDBusArgument const& argument,
                                           Message &message);
 
    QString getUser() const;
    QString getText() const;
 
    //register Message with the Qt type system
    static void registerMetaType();
 
private:
    QString m_user;
    QString m_text;
};
 
Q_DECLARE_METATYPE(Message)
 
#endif // MESSAGE_H
