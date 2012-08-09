cmake_minimum_required(VERSION 2.8)
find_package(Qt4 COMPONENTS QtCore QtDBus QtGui REQUIRED)
include(${QT_USE_FILE})

set(DBUS_CHAT_SRCS
      ChatAdaptor.cpp
      Chat.cpp
      ChatInterface.cpp
      ChatWindow.cpp
      main.cpp
      Message.cpp
   )

set(DBUS_CHAT_MOC_FILES
      ChatAdaptor.h
      Chat.h
      ChatInterface.h
      ChatWindow.h
   )

set(DBUS_CHAT_UI_FILES
      ../ui/ChatWindow.ui
   )

QT4_WRAP_CPP(DBUS_CHAT_SRCS ${DBUS_CHAT_MOC_FILES})
QT4_WRAP_UI(DBUS_CHAT_SRCS ${DBUS_CHAT_UI_FILES})

# So we can find generated ui_*.h files
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(DBusChat ${DBUS_CHAT_SRCS})
target_link_libraries(DBusChat ${QT_LIBRARIES})
