#include "pendulumparam.h"

PendulumParam::PendulumParam(int pixelResolutionX, int pixelResolutionY, int spiSpeed, int brightness)
{
    this->pixelResolutionX = pixelResolutionX;
    this->pixelResolutionY = pixelResolutionY;
    this->brightness =brightness;
    this->spiSpeed =spiSpeed;
}

void PendulumParam::setPixelResolutionY(int pixelResolutionY)
{
    this->pixelResolutionY = pixelResolutionY;
}

void PendulumParam::setPixelResolutionX(int pixelResolutionX)
{
    this->pixelResolutionX = pixelResolutionX;
}

void PendulumParam::setBrightness(int brightness)
{
    this->brightness = brightness;
}

void PendulumParam::setSpiSpeed(int spiSpeed)
{
    this->spiSpeed = spiSpeed;
}

int PendulumParam::getPixelResolutionX()
{
    return this->pixelResolutionX;
}

int PendulumParam::getPixelResolutionY()
{
    return this->pixelResolutionY;
}

int PendulumParam::getBrightness()
{
    return this->brightness;
}

int PendulumParam::getSpiSpeed()
{
    return this->spiSpeed;
}
