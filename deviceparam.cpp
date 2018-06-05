#include "deviceparam.h"
#include <QSettings>
#include <QDir>
#include <QDebug>

DeviceParam::DeviceParam(QObject *parent) : QObject(parent)
{
    this->settingsPath = QDir::currentPath() + "/device.ini";
    loadSettings();
}

DeviceParam::DeviceParam(QString name)
{
    this->settingsPath = QDir::currentPath() + "/" + name;
    loadSettings();
}

void DeviceParam::loadSettings()
{
    QSettings settings(this->settingsPath, QSettings::NativeFormat);
    settings.beginGroup( "DeviceSettings" );
    this->resX = settings.value("resX", 180).toInt();
    this->resY = settings.value("resY", 72).toInt();
    this->spiSpeed = settings.value("spiSpeed", 1000000).toInt();
    this->brightness = settings.value("brightness", 100).toInt();
    this->sensorType = settings.value("sensorType", "mpu").toString();
    this->brightness = settings.value("frameDelay", 2000).toInt();
}

int DeviceParam::getFrameDelay() const
{
    return frameDelay;
}

void DeviceParam::setFrameDelay(int value)
{
    frameDelay = value;
}

QString DeviceParam::getSensorType() const
{
    return sensorType;
}

void DeviceParam::setSensorType(const QString &value)
{
    sensorType = value;
}

int DeviceParam::getBrightness() const
{
    return brightness;
}

void DeviceParam::setBrightness(int value)
{
    brightness = value;
}

int DeviceParam::getSpiSpeed() const
{
    return spiSpeed;
}

void DeviceParam::setSpiSpeed(int value)
{
    spiSpeed = value;
}

int DeviceParam::getResX() const
{
    return resX;
}

void DeviceParam::setResX(int value)
{
    resX = value;
}

int DeviceParam::getResY() const
{
    return resY;
}

void DeviceParam::setResY(int value)
{
    resY = value;
}
