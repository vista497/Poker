#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
#include "pack.h"
#include "QDebug"
#include <QMessageBox>


class Player
{
    Card cards[2];
    Pack* pack;
    QString PlayerName;
    QString cardName;


    QMessageBox msg;
    QString rangMaxT;
    QString combT;
    QString combwithMaxrang;
    QString* rangName;
    int* value;
    int* valueR;
    int* suit;
    int combaT;
    int flesh;
    int strit;
    bool error;



public:
    Player();

    void SetPlayer(QString cardName, QString playerName);
    QString combPlayer(int* tableCards, int* playerCards);
   int returnCombaT();



};

#endif // PLAYER_H
