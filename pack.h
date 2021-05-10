#ifndef PACK_H
#define PACK_H
#include "card.h"
#include "QApplication"

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
    QString allCardsOnTableFunc(QVector<int> allCardsTable, QVector<int> CardsPlayer, QVector<int> CardsTable, QVector<int> CardsPlyer2);
    int* allCardOnTable;
    int* closeCards;
    QVector<int> closeCardsVector;
    int* openCards;
    QVector<int> openCardsVector;
    int* valueAut;
    QVector<int> valueAutVectro;
    int* suitAut;
    QVector<int> suitAutVector;
    int* valueOpen;
    QVector<int> valueOpenVector;
    int* suitOpen;
    QVector<int> suitOpenVector;
    int* valueClose;
    QVector<int> valueCloseVector;
   // int* suitClose;
    QVector<int> suitCloseVector;
    int getValueAut(int &y);
    int getSuitAut(int &y);
    QString getCardAut(int y, int &z);
    QString getNameCardAut(QString &arg);
    QString NameAut;
        double persent;
        double draw;
        double set=50000;



};

#endif // PACK_H
