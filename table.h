#ifndef TABLE_H
#define TABLE_H
#include "card.h"
#include "player.h"
#include "pack.h"




class Table
{

    Pack* pack;
    int tableCards[5];
    QString rangMaxT;
    QString combT;
    QString combwithMaxrang;
    QString* rangName;
    int* value;
    int combaT;

public:
    Table();
    Pack* packTable;
    int m_player;
    void SetCardTable(int arg, int x);
    int* getCardTable();
    void SetCardTableVector(int arg);
        QVector<int> tableCardsVector;
        void delCard(int arg,int i);

        double percent;
};

#endif // TABLE_H
