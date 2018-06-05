#ifndef IMAGECONVERTOR_H
#define IMAGECONVERTOR_H
#include "abstractimageconvertor.h"
#include <QVector>
#include <QImage>
#include <QMutex>
#include "Network/message.h"

class ImageConvertor : public AbstractImageConvertor
{
    Q_OBJECT
public:
    ImageConvertor(QObject *parent = 0, DeviceParam *dp = new DeviceParam());
    QByteArray getImageLine(float qValue);
    bool isEmpty();

public slots:
    void convertMessage(Message msg);

private:
    QMutex m_mutex;
    void convertImage(QImage img, QString param);
    QByteArray polarConvertor(uint8_t *array);
    QByteArray *blackLine;
    int lineShiftCounter(float qValue);
    QVector<QByteArray> *imageDataList;
    QByteArray imageData;
};

#endif // IMAGECONVERTOR_H
