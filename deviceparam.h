#ifndef DEVICEPARAM_H
#define DEVICEPARAM_H

#include <QObject>

class DeviceParam : public QObject
{
    Q_OBJECT
public:
    explicit DeviceParam(QObject *parent = nullptr);
    DeviceParam(QString name);
    int getResY() const;
    void setResY(int value);

    int getResX() const;
    void setResX(int value);

    int getSpiSpeed() const;
    void setSpiSpeed(int value);

    int getBrightness() const;
    void setBrightness(int value);

    QString getSensorType() const;
    void setSensorType(const QString &value);

    int getFrameDelay() const;
    void setFrameDelay(int value);
    
signals:
    
public slots:
private:
    QString settingsPath;
    void loadSettings();
    int resY;
    int resX;
    int spiSpeed;
    int brightness;
    int frameDelay;
    QString sensorType;
};

#endif // DEVICEPARAM_H
