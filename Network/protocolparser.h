#ifndef PROTOCOLPARSER_H
#define PROTOCOLPARSER_H

#include "message.h"
#include "parseexception.h"

#define FULL_LENGTH_START   0
#define JSON_LENGTH_START   3
#define TYPE_START          6
#define JSON_START          7
#define FULL_LENGTH_B   3
#define JSON_LENGTH_B   3
#define HEADERS_SHIFT_B 7

enum {COMMAND = 1, DATA = 2};
#define FULL_LENGTH_B 3

class ProtocolParser
{
public:
    static Message* parseData(QByteArray data);
    static long getFullLength(QByteArray data);
    static long getJsonLength(QByteArray data);
};

#endif // PROTOCOLPARSER_H
