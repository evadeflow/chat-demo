#!/usr/bin/env python
import dbus

bus = dbus.SessionBus()
chatservice = bus.get_object('demo.dbus.chat', '/chat')

add_user = chatservice.get_dbus_method('addUser', 'demo.Chat')
add_user('Alan')
add_user('Brad')
add_user('Cara')

send_msg = chatservice.get_dbus_method('sendMessage', 'demo.Chat')
msg1 = ('Alan', 'Msg from Alan!')
msg2 = ('Brad', 'Msg from Brad!')
msg3 = ('Cara', 'Msg from Cara!')
print send_msg([msg1, msg2, msg3])
