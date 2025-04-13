QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    accountslist.cpp \
    car.cpp \
    creditcard.cpp \
    login.cpp \
    luxlist.cpp \
    luxurious.cpp \
    main.cpp \
    customer.cpp \
    modify_info.cpp \
    ordinary.cpp \
    ordinarylist.cpp \
    original_map.cpp \
    payment.cpp \
    payment_window.cpp \
    personalinfo.cpp \
    route_popup.cpp \
    service_choice.cpp \
    setcredit.cpp \
    signup.cpp \
    taxi.cpp \
    taxilist.cpp \
    wallet.cpp

HEADERS += \
    account.h \
    accountslist.h \
    car.h \
    creditcard.h \
    customer.h \
    login.h \
    luxlist.h \
    luxurious.h \
    modify_info.h \
    ordinary.h \
    ordinarylist.h \
    original_map.h \
    payment.h \
    payment_window.h \
    personalinfo.h \
    route_popup.h \
    service_choice.h \
    setcredit.h \
    signup.h \
    taxi.h \
    taxilist.h \
    wallet.h

FORMS += \
    customer.ui \
    login.ui \
    modify_info.ui \
    original_map.ui \
    payment_window.ui \
    route_popup.ui \
    service_choice.ui \
    setcredit.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
