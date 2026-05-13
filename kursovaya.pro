QT += core widgets charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Для экспорта в Excel (только Windows + Qt5)
win32:!winrt {
    contains(QT_VERSION, ^5\\.[0-9]+\\.[0-9]+$) {
        QT += axcontainer
        DEFINES += HAS_AXCONTAINER
        message("ActiveQt support enabled for Excel export")
    } else {
        message("Excel export disabled (requires Qt5 on Windows)")
    }
} else {
    message("Excel export disabled (Windows + Qt5 only)")
}

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui
