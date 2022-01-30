QT += quick \
    widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ixbutton.cpp \
        ixdynamiccomponent.cpp \
        ixhandlebackpopup.cpp \
        ixloginscreen.cpp \
        ixregistry.cpp \
        ixscreenlogic.cpp \
        ixshadowtextfield.cpp \
        ixstartupscreen.cpp \
        ixtextfield.cpp \
        ixwindow.cpp \
        ixwindowfocushandler.cpp \
        ixwindownavigationhandler.cpp \
        ixwindowpage.cpp \
        ixwindowpageheader.cpp \
        ixwindowtabhandler.cpp \
        main.cpp

RESOURCES += qml.qrc \
    component.qrc \
    control.qrc \
    page.qrc \
    screen.qrc \
    screenheader.qrc

TRANSLATIONS += \
    Innox_pl_PL.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ixbutton.h \
    ixdynamiccomponent.h \
    ixhandlebackpopup.h \
    ixloginscreen.h \
    ixregistry.h \
    ixscreenlogic.h \
    ixshadowtextfield.h \
    ixstartupscreen.h \
    ixtextfield.h \
    ixwindow.h \
    ixwindowfocushandler.h \
    ixwindownavigationhandler.h \
    ixwindowpage.h \
    ixwindowpageheader.h \
    ixwindowtabhandler.h
