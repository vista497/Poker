#ifndef CARD_H
#define CARD_H
#include <QString>

class Card
{
    int id=0;
    int m_value;
    int m_suit;
    QString name;
    QString m_str_value;
    QString m_str_suit;

public:
    Card(){m_value=0; m_suit=0; name="";};
    Card(int &x, int &y);
    QString SetCard(int &x, int &y);
    QString getName(int &arg);
    int getCardValue();
    int getCardSuit();
    int getid();
    //Card operator=(Card &arg1);



};

#endif // CARD_H
