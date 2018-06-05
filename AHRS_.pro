QT       += core network

#QT       += gui

TARGET = AHRS_
CONFIG += console c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    AHRS/AHRS.cpp \
    Common/gpio.cpp \
    Common/I2Cdev.cpp \
    Common/LSM9DS1.cpp \
    Common/MPU9250.cpp \
    Common/Util.cpp \
    Network/message.cpp \
    Network/piserver.cpp \
    Network/protocolparser.cpp \
    Pendulum/apa102display.cpp \
    Pendulum/imageconvertor.cpp \
    Pendulum/inertialsensorfactory.cpp \
    Pendulum/pendulumparam.cpp \
    deviceparam.cpp \
    main.cpp \
    serverthread.cpp

HEADERS += \
    AHRS/AHRS.hpp \
    Common/gpio.h \
    Common/I2Cdev.h \
    Common/InertialSensor.h \
    Common/LSM9DS1.h \
    Common/MPU9250.h \
    Common/SPIdev.h \
    Common/Util.h \
    Network/message.h \
    Network/parseexception.h \
    Network/piserver.h \
    Network/protocolparser.h \
    Pendulum/abstractimageconvertor.h \
    Pendulum/abstractlinedisplay.h \
    Pendulum/apa102display.h \
    Pendulum/imageconvertor.h \
    Pendulum/inertialsensorfactory.h \
    Pendulum/pendulumparam.h \
    deviceparam.h \
    serverthread.h
