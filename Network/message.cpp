#include "message.h"

Message::Message()
{
    imageList = new QList<QImage>();
}

void Message::addToImageList(QImage img)
{
    imageList->append(img);
}

QList<QImage>* Message::getImageList()
{
    return imageList;
}

QJsonObject Message::getCommands() const
{
    return commands;
}

void Message::setCommands(const QJsonObject &value)
{
    commands = value;
}
