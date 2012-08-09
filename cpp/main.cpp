#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusConnectionInterface>
#include <QtGui/QApplication>
 
#include "Chat.h"
#include "ChatAdaptor.h"
#include "ChatInterface.h"
#include "ChatWindow.h"
#include "Message.h"
 
#define CHAT_SERVICE "demo.dbus.chat"
#define CHAT_PATH "/chat"
 
int main(int argc, char *argv[])
{
    Message::registerMetaType();
 
    QApplication app(argc, argv);
    Chat* pChat = NULL;
 
    // Create a Chat instance and register it with the session bus only if the
    // service isn't already available.
    QDBusConnection connection = QDBusConnection::sessionBus();
    if (!connection.interface()->isServiceRegistered(CHAT_SERVICE)) {
        pChat = new Chat(&app);

        // Note: The Qt type system hangs on to a reference to this object,
        // so we don't need to
        new ChatAdaptor(pChat);
 
        if (!connection.registerService(CHAT_SERVICE)) {
            qFatal("Could not register service!");
        }
 
        if (!connection.registerObject(CHAT_PATH, pChat)) {
            qFatal("Could not register Chat object!");
        }
    }
 
    demo::Chat chatInterface(CHAT_SERVICE, CHAT_PATH, connection);
 
    ChatWindow w(chatInterface);
    w.show();
 
    int ret = app.exec();
 
    if (pChat) {
        delete pChat;
    }
 
    return ret;
}
