TEMPLATE = subdirs

SUBDIRS += \
    ryderdb \
    ryderdb-cli \
    ryderdb-test


ryderdb-test.depends =ryderdb
ryder-cli.depends = ryderdb


CONFIG += console c++17
CONFIG -= app_bundle 
CONFIG -= qt 

SOURCES += 

HEADERS +=