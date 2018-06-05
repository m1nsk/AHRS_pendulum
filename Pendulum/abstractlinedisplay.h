#ifndef ABSTRACTLINEDISPLAY_H
#define ABSTRACTLINEDISPLAY_H

#include "deviceparam.h"

class AbstractLineDisplay
{
public:
    virtual void transfer(QByteArray pixelArray){}
protected:
    DeviceParam *dp;
signals:

public slots:
};

#endif // ABSTRACTLINEDISPLAY_H
