#ifndef USERDATA_H
#define USERDATA_H

#include <qstring.h>

class userdata
{
public:
    userdata();
    static QString getCardId();
    static QString getCardType();
    static QByteArray getWebToken();


    static QString cardId;
    static QString cardType;
    static QByteArray webToken;

private:


};

#endif // USERDATA_H
