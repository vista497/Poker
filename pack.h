#ifndef PACK_H
#define PACK_H
#include "card.h"

class Pack
{

    int count;
    QString cardName;
public:
   Pack();
   Card *cards;
   Card *cardsAut;
    QString getCard(int y, int &z);
    QString getNameCard(QString &arg);
    int getValue(int &y);
    int getSuit(int &y);
    QString allCardsOnTableFunc(int* allCardsTable, int* CardsPlayer, int* CardsTable);
    int* allCardOnTable;
    int* closeCards;
    int* openCards;
    int* valueAut;
    int* suitAut;
    int* valueOpen;
    int* suitOpen;
    int* valueClose;
    int* suitClose;
    int getValueAut(int &y);
    int getSuitAut(int &y);
    QString getCardAut(int y, int &z);
    QString getNameCardAut(QString &arg);
    QString NameAut;


    int score;
};

#endif // PACK_H
