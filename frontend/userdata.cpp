#include "userdata.h"

userdata::userdata()
{

}

QString userdata::getCardId()
{
    return cardId;
}

QString userdata::getCardType()
{
    return cardType;

}

QByteArray userdata::getWebToken()
{
    return webToken;
}

QString userdata::getAccountId()
{
    return accountId;
}

int userdata::getBalance()
{
    return balance;
}

int userdata::getCreditLimit()
{
    return credit_limit;
}

QByteArray userdata::webToken{
    "none"
    //http://myAzure.com
};

QString userdata::cardId{
    "none"
    //http://myAzure.com
};

QString userdata::cardType{
    "debit"
    //http://myAzure.com
};

QString userdata::accountId{
    "none"
    //http://myAzure.com
};

int userdata::balance{
    0
    //http://myAzure.com
};

int userdata::credit_limit{
    0
    //http://myAzure.com
};
