#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QJsonObject>
#include <QImage>
#include <QVector>

class Message
{
public:
    explicit Message();
    void addToImageList(QImage img);
    QList<QImage>* getImageList();

    QJsonObject getCommands() const;
    void setCommands(const QJsonObject &value);

private:
    QList<QImage> *imageList;
    QJsonObject commands;
};

#endif // MESSAGE_H
