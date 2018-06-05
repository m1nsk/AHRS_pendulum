#include "apa102display.h"

Apa102Display::Apa102Display(DeviceParam *dp)
{
    this->dp = dp;
    this->device = "/dev/spidev1.0";
}

void Apa102Display::transfer(QByteArray pixelArray)
{
    uint8_t tx[this->dp->getResY()*4 + 5];
    uint8_t rx[this->dp->getResY()*4 + 4];
    memcpy(tx + 4, pixelArray.data() - 1, this->dp->getResY()*4);
    for(int i = 0; i < 4; i++) {
        tx[i] = 0;
    }

    SPIdev::transfer(this->device, tx, rx, this->dp->getResY() * 4, this->dp->getSpiSpeed());
}
