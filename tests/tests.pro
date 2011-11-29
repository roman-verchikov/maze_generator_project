#-------------------------------------------------
#
# Project created by QtCreator 2011-11-24T19:58:43
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = maze_generator_test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += maze_generator_test.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

INCLUDEPATH += ../maze_generator_lib



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../maze_generator_lib/release/ -lmaze_generator_lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../maze_generator_lib/debug/ -lmaze_generator_lib
else:symbian: LIBS += -lmaze_generator_lib
else:unix: LIBS += -L$$OUT_PWD/../maze_generator_lib/ -lmaze_generator_lib

INCLUDEPATH += $$PWD/../maze_generator_lib
DEPENDPATH += $$PWD/../maze_generator_lib

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../maze_generator_lib/release/maze_generator_lib.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../maze_generator_lib/debug/maze_generator_lib.lib
else:unix:!symbian: PRE_TARGETDEPS += $$OUT_PWD/../maze_generator_lib/libmaze_generator_lib.a
