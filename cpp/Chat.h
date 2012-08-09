#ifndef CHAT_H
#define CHAT_H
 
#include <QObject>
#include <QStringList>
 
class Message;
 
class Chat : public QObject
{
    Q_OBJECT
 
    Q_CLASSINFO("D-Bus Interface", "demo.Chat")
    Q_PROPERTY( QStringList users READ users)
 
signals:
    void userAdded(QString const& user);
    void userRemoved(QString const& user);
 
    void messageSent(Message const& message);
 
public slots:
    void addUser(QString const& user);
    void removeUser(QString const& user);
 
    void sendMessage(Message const& message);
 
public:
    Chat(QObject* parent = 0);
    virtual ~Chat();
 
    QStringList users() const;
 
private:
    QStringList m_users;
};

#endif // CHAT_H
