#ifndef TABLE_H
#define TABLE_H
#include "card.h"
#include "player.h"
#include "pack.h"



class Table
{
    //Player players[2];


    Pack* pack;
    int tableCards[5];
    //QMessageBox msg;
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
  //  QString getArrCardTable();
    int* AutPlyer();
};

#endif // TABLE_H
