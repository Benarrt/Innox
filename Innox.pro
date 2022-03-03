QT += quick

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ixbackendlesreqdefs.cpp \
        ixbackendless.cpp \
        ixbutton.cpp \
        ixdynamic.cpp \
        ixdynamiccomponent.cpp \
        ixdynamiccreationlogic.cpp \
        ixemailinput.cpp \
        ixemaillogic.cpp \
        ixhandlebackpopup.cpp \
        ixloginlogic.cpp \
        ixloginscreen.cpp \
        ixpageindicator.cpp \
        ixpageindicatorlogic.cpp \
        ixpasswordinput.cpp \
        ixpasswordlogic.cpp \
        ixpasswordrecoverlogic.cpp \
        ixqcomponent.cpp \
        ixregisterlogic.cpp \
        ixregistry.cpp \
        ixscreen.cpp \
        ixscreenlogic.cpp \
        ixshadowtextfield.cpp \
        ixstartupscreen.cpp \
        ixstylesheet.cpp \
        ixswipeview.cpp \
        ixtextfield.cpp \
        ixwindow.cpp \
        ixwindowfocushandler.cpp \
        ixwindownavigationhandler.cpp \
        ixwindowpage.cpp \
        ixwindowpagefooter.cpp \
        ixwindowpageheader.cpp \
        ixwindowtabhandler.cpp \
        main.cpp

RESOURCES += qml.qrc \
    ScreenFooter.qrc \
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
    ixbackendlesreqdefs.h \
    ixbackendless.h \
    ixbutton.h \
    ixdynamic.h \
    ixdynamiccomponent.h \
    ixdynamiccreationlogic.h \
    ixemailinput.h \
    ixemaillogic.h \
    ixhandlebackpopup.h \
    ixloginlogic.h \
    ixloginscreen.h \
    ixpageindicator.h \
    ixpageindicatorlogic.h \
    ixpasswordinput.h \
    ixpasswordlogic.h \
    ixpasswordrecoverlogic.h \
    ixqcomponent.h \
    ixregisterlogic.h \
    ixregistry.h \
    ixscreen.h \
    ixscreenlogic.h \
    ixshadowtextfield.h \
    ixstartupscreen.h \
    ixstylesheet.h \
    ixswipeview.h \
    ixtextfield.h \
    ixwindow.h \
    ixwindowfocushandler.h \
    ixwindownavigationhandler.h \
    ixwindowpage.h \
    ixwindowpagefooter.h \
    ixwindowpageheader.h \
    ixwindowtabhandler.h
