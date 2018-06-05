#include "imageconvertor.h"
#include <math.h>
#define PI 3.14159265

ImageConvertor::ImageConvertor(QObject *parent, DeviceParam* dp) :
    AbstractImageConvertor(parent)
{
    this->dp = dp;
    this->imageDataList = new QVector<QByteArray>;
    this->blackLine = new QByteArray();
    for(int i = 0; i < this->dp->getResY(); i++) {
        this->blackLine->append(QByteArray::fromRawData("\xFF\x00\x00\x00", 4));
    }
}

void ImageConvertor::convertImage(QImage img, QString param)
{
    img = img.scaled(QSize(dp->getResY(), dp->getResX()),Qt::IgnoreAspectRatio);
    img = img.convertToFormat(QImage::Format_RGB32);
    this->imageDataList->append(polarConvertor(img.bits()));
    //this->imageData = polarConvertor(img->bits());
}

void ImageConvertor::convertMessage(Message msg)
{
    m_mutex.lock();
    QList<QImage> *imgList = msg.getImageList();
    while (!imgList->isEmpty())
        convertImage(imgList->takeFirst(), "");
    this->imageData = this->imageDataList->at(0);
    m_mutex.unlock();
}

QByteArray ImageConvertor::polarConvertor(uint8_t *array)
{
    const int DELTA_X = dp->getResX() / 2;
    const uint8_t BLACK_PIXEL[4] = {255, 0, 0, 0};
    char polar[dp->getResX() * dp->getResY() * 4];
    for(int a = 0; a < dp->getResX(); a++) {
        for(int l = 0; l < dp->getResY(); l++) {
            int x = (int)(DELTA_X - l * cos(a * PI / 180));
            if(x < 0 || x >= dp->getResX()) {
                memcpy(&polar[(a * dp->getResY() + l) * 4], BLACK_PIXEL, 4);
            } else{
                int y = l * sin(a * PI / 180);
                memcpy(&polar[(a * dp->getResY() + l) * 4], &array[(x * dp->getResY() + y) * 4], 4);
            }
        }
    }
    return QByteArray::fromRawData(polar, dp->getResX() * dp->getResY() * 4);
}

int ImageConvertor::lineShiftCounter(float qValue)
{
    return this->dp->getResX() / 2 + qValue * 2 * 90 / sqrt(2);
}

QByteArray ImageConvertor::getImageLine(float qValue)
{
    QMutexLocker locker (&m_mutex);
    int lineNum = lineShiftCounter(qValue);
    if (lineNum < 0 || lineNum >= this->dp->getResX()) {
        QByteArray bl;
        for(int i = 0; i < this->dp->getResY(); i++) {
            bl.append(QByteArray::fromRawData("\xFF\x00\x00\x00", 4));
        }
        return bl;
    }
    return this->imageData.mid(this->dp->getResY() * lineNum * 4, this->dp->getResY() * 4);
}

bool ImageConvertor::isEmpty()
{
    if (this->imageData.size())
        return true;
    return false;
}
