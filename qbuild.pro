TEMPLATE=app
TARGET=qtbackup

CONFIG+=qtopia

# I18n info
STRING_LANGUAGE=en_US
LANGUAGES=en_US

# Package info
pkg [
    name=qtbackup
    desc="Backup Settings"
    license=GPL
    version=1.0
    maintainer="Ghislain <info@openmobile.nl>"
]

desktop [
    hint=desktop
    files=qtbackup.desktop
    path=/apps/Applications
]

pics [
    hint=pics
    files=pics/*
    path=/pics/qtbackup
]

extras_bin [
    hint=image generated
    files = qtbackup.sh
    files+= qtbackup.conf 
    path = /
]

# Input files
FORMS=\
    MainForm.ui

HEADERS=\
    MainForm.h

SOURCES=\
    Main.cpp\
    MainForm.cpp

# Install rules
target [
    hint=sxe
    domain=untrusted
]

