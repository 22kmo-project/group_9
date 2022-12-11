#ifndef USERDATA_H
#define USERDATA_H

#include <qstring.h>

class userdata
{
public:
    userdata();
    static QString getCardId();
    static QString getCardType();
    static QString getAccountId();
    static int getBalance();
    static int getCreditLimit();


    static QByteArray getWebToken();


    static QString cardId;
    static QString cardType;
    static QString accountId;
    static int balance;
    static int credit_limit;


    static QByteArray webToken;

private:


};

#endif // USERDATA_H
