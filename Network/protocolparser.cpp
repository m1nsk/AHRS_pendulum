#include "protocolparser.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QImage>

Message* ProtocolParser::parseData(QByteArray data)
{
    Message *message = new Message();
    long fullSize = getFullLength(data);
    long jsonSize = getJsonLength(data);
    int messageType = data[TYPE_START];
    int dataShift = HEADERS_SHIFT_B + jsonSize;

    if (dataShift > fullSize)
        return NULL;

    QJsonDocument jDoc = QJsonDocument::fromJson(data.mid(JSON_START, jsonSize));
    if (!&jDoc)
        return NULL;
    QJsonObject jObj = jDoc.object();
    if (messageType == DATA) {
        QJsonArray images = jObj["images"].toArray();
        foreach (const QJsonValue & obj, images){
            QString type = obj.toObject().value(QString("type")).toString();
            int pos = obj.toObject().value(QString("pos")).toInt();
            int len = obj.toObject().value(QString("len")).toInt();
            QString name = obj.toObject().value(QString("name")).toString();
            if ((dataShift + pos >= fullSize) || (dataShift + pos + len - 1 > fullSize))
                return NULL;
            QByteArray aa = data.mid(dataShift + pos, 8);
            QImage *image = new QImage();
            *image = QImage::fromData(data.mid(dataShift + pos, dataShift + pos + len));
            if (!image->isNull()) {
                message->addToImageList(*image);
            }
        }
    }
    QJsonObject commands = jObj["commands"].toObject();
    if (!&commands)
        return NULL;
    message->setCommands(jObj["commands"].toObject());
    return message;
}

long ProtocolParser::getFullLength(QByteArray data)
{
    return (unsigned long)(((uint8_t)data[FULL_LENGTH_START]<<16)
                           + ((uint8_t)data[FULL_LENGTH_START + 1]<<8)
            + (uint8_t)data[FULL_LENGTH_START + 2]);
}

long ProtocolParser::getJsonLength(QByteArray data)
{
    return (unsigned long)(((uint8_t)data[JSON_LENGTH_START]<<16)
                                        + ((uint8_t)data[JSON_LENGTH_START + 1]<<8)
                                        + (uint8_t)data[JSON_LENGTH_START + 2]);
}
