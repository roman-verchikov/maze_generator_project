#-------------------------------------------------
#
# Project created by QtCreator 2011-10-22T19:11:35
#
#-------------------------------------------------

QT       += core gui

TARGET = maze_generator_view
TEMPLATE = app

SOURCES +=  main.cpp \
	mainwindow.cpp \
	maze_drawing_widget.cpp \
	room_drawer.cpp

HEADERS += mainwindow.h \
	maze_drawing_widget.h \
	room_drawer.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++0x

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += libboost-dev

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../maze_generator_lib/release/ -lmaze_generator_lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../maze_generator_lib/debug/ -lmaze_generator_lib
else:symbian: LIBS += -lmaze_generator_lib
else:unix: LIBS += -L$$OUT_PWD/../maze_generator_lib/ -lmaze_generator_lib

INCLUDEPATH += $$PWD/../maze_generator_lib
DEPENDPATH += $$PWD/../maze_generator_lib

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../maze_generator_lib/release/maze_generator_lib.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../maze_generator_lib/debug/maze_generator_lib.lib
else:unix:!symbian: PRE_TARGETDEPS += $$OUT_PWD/../maze_generator_lib/libmaze_generator_lib.a
