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

QByteArray userdata::webToken{
    "none"
    //http://myAzure.com
};

QString userdata::cardId{
    "none"
    //http://myAzure.com
};

QString userdata::cardType{
    "none"
    //http://myAzure.com
};
