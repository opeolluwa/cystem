TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

include(../ryderdb/Defines.pri)

macx:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ryderdb/ -lryderdb
else:macx:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ryderdb/ -lryderdb
