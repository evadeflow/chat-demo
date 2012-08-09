#ifndef CHATWINDOW_H
#define CHATWINDOW_H
 
#include <QtGui/QMainWindow>
#include <QtGui/QStringListModel>
 
#include "ChatInterface.h"
 
namespace Ui
{
    class ChatWindow;
}
 
class QCloseEvent;
 
class ChatWindow : public QMainWindow
{
    Q_OBJECT
 
public:
    ChatWindow(demo::Chat& chatInterface, QWidget *parent = 0);
    virtual ~ChatWindow();
 
protected:
    virtual void closeEvent(QCloseEvent *event);
 
private:
    ChatWindow(ChatWindow const& other);
    ChatWindow& operator=(ChatWindow const& other);
 
    Ui::ChatWindow *ui;
 
    QString m_userName;
 
    QStringListModel m_users;
 
    demo::Chat &m_chatInterface;
 
private slots:
    void sendMessage();
 
    void chat_userAdded(QString const& user);
    void chat_userRemoved(QString const& user);
    void chat_messageSent(Message const& message);
};
 
#endif // CHATWINDOW_H
