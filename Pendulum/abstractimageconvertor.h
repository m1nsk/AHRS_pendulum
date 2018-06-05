#ifndef ABSTRACTIMAGECONVERTOR_H
#define ABSTRACTIMAGECONVERTOR_H

#include "deviceparam.h"
#include "Network/message.h"

class AbstractImageConvertor: public QObject
{
    Q_OBJECT
public:
    explicit AbstractImageConvertor(QObject *parent = 0){}
    virtual bool isEmpty(){}
    virtual QByteArray getImageLine(float qValue){}
public slots:
    virtual void convertMessage(Message msg){}
protected:
    DeviceParam* dp;
signals:

public slots:
};

#endif // ABSTRACTIMAGECONVERTOR_H
