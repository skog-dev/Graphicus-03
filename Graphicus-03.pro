TEMPLATE     = vcapp
TARGET       = Graphicus-03
CONFIG      += warn_on qt debug windows console
HEADERS     += mainInterface.h
SOURCES     += Graphicus-03.cpp mainInterface.cpp
INCLUDEPATH += ../GraphicusGUI
LIBS        += ../GraphicusGUI/graphicusGUI.lib
QT          += widgets
