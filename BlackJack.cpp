#include <iostream>
#include "BlackJack.h"

Card::Card():suit(diamonds), name(two), value(2){};

Card::Card(cardsuit s, cardname n):suit(s), name(n)
{
    setValue();
};

void Card::flip()
{
    isUpsideDown = !isUpsideDown;
}

int Card::getValue()
{
    return value;
}

void Card::setValue()
{
    if(name<11) value=(int)name;
    else value=10;
}
