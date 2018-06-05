#ifndef PENDULUMPARAM_H
#define PENDULUMPARAM_H

class PendulumParam
{
public:
    PendulumParam(int pixelResolutionX = 150, int pixelResolutionY = 60, int spiSpeed = 1000000, int brightness = 100);

    int getPixelResolutionX();
    int getPixelResolutionY();
    int getBrightness();
    int getSpiSpeed();
private:
    void setPixelResolutionY(int pixelResolutionY);
    void setPixelResolutionX(int pixelResolutionX);
    void setBrightness(int brightness);
    void setSpiSpeed(int spiSpeed);
    int pixelResolutionY;
    int pixelResolutionX;
    int spiSpeed;
    int brightness;
};

#endif // PENDULUMPARAM_H
