#ifndef APA102DISPLAY_H
#define APA102DISPLAY_H
#include "abstractlinedisplay.h"
#include "Common/SPIdev.h"

class Apa102Display : public AbstractLineDisplay
{
public:
    Apa102Display(DeviceParam* dp = new DeviceParam());
    void transfer(QByteArray pixelArray);
public:
    char *device;
};

#endif // APA102DISPLAY_H
