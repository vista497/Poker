#include "pack.h"
#include "QDebug"
#include "algorithm"
#include "player.h"
#include "random"
#include "mainwindow.h"

using namespace std;

Pack::Pack()
{
    count=52;
    int i=0;
    cards=new Card[count];
    //cards[0].SetCard(i,j);
    for (int x=0; x<4; x++)
    {
        for (int y=0; y<13; y++)
        {

            cards[i++].SetCard(x,y);
        }
    }


}
QString Pack::getCard(int y, int &z)
{
    return cards[y].getName(z);

}
int Pack::getValue(int &y) //возвращает ранг карты по номеру
{
    return cards[y].getCardValue();
}

int Pack::getSuit(int &y) //возвращает масть карты по номеру
{
    return cards[y].getCardSuit();
}

QString Pack::getNameCard(QString &arg)
{
    int z=3; // значение
    int w=1;//полное имя
    for(int y=0;y<52;y++)
    {
        if(cards[y].getName(w)==arg)
            return cards[y].getName(z);
    }
}

QString Pack::allCardsOnTableFunc(QVector<int> allCardsTable, QVector<int> CardsPlyer, QVector<int> CardsTable, QVector<int> CardsPlyer2)
{
    //находим длину массива
    int len=allCardsTable.size();

    openCardsVector=allCardsTable;

    //получаем массив закрытых карт
    for(int x=0;x<52;x++)
        closeCardsVector.push_back(x);
    for(int x=0; x<len;x++)
        closeCardsVector.erase(remove(closeCardsVector.begin(), closeCardsVector.end(),openCardsVector[x]),closeCardsVector.end());

    //получаем ранг карт и масть закрытых карт
    int len1=closeCardsVector.size();
    for(int x=0;x<len1;x++)
    {
        for(int r=0;r<52;r++)
        {
            if(r==closeCardsVector[x])
            {
                valueCloseVector.push_back(getValue(r));
                suitCloseVector.push_back(getSuit(r));
            }
        }
    }

    //получаем ранг и масть открытых карт
    int lenn=openCardsVector.size();
    for(int x=0;x<lenn;x++)
    {
        for(int r=0;r<52;r++)
        {
            if(r==openCardsVector[x])
            {
                valueOpenVector.push_back(getValue(r));
                suitOpenVector.push_back(getSuit(r));
            }
        }
    }

    vector<int>combinatoin;

    Player *player=new Player();
    int CardPlayer1[2];
    CardPlayer1[0]=CardsPlyer[0];
    CardPlayer1[1]=CardsPlyer[1];
    int CardPlayer2[2];
    CardPlayer2[0]=CardsPlyer2[0];
    CardPlayer2[1]=CardsPlyer2[1];

    int combM[2];
    double value=0;
    double score=0;


    vector<int>valuePlayers;
    for(int x=0;x<2;x++)
    {
        valuePlayers.push_back(getValue(CardsPlyer[x]));
    }
    for(int x=0;x<2;x++)
    {
        valuePlayers.push_back(getValue(CardsPlyer2[x]));
    }

    //получаем рандомную комбинацию карт на столе много раз
    qApp->processEvents();
    for (int x=0; x<set; x++){
        int combinationMass[5];
        for(int y=0; y<5;y++){
            for(int x=0;x<5;x++)
                std::random_shuffle(closeCardsVector.begin(), closeCardsVector.end());

            if (CardsTable.size()<3)
                combinationMass[y]=closeCardsVector[y+25];


            if (CardsTable.size()==3)
            {
                combinationMass[0]=CardsTable[0];
                combinationMass[1]=CardsTable[1];
                combinationMass[2]=CardsTable[2];
                if (y==3)
                    combinationMass[y]=closeCardsVector[y+25];
            }
            if (CardsTable.size()==4)
            {
                combinationMass[0]=CardsTable[0];
                combinationMass[1]=CardsTable[1];
                combinationMass[2]=CardsTable[2];
                combinationMass[3]=CardsTable[3];
                if (y==4)
                    combinationMass[y]=closeCardsVector[y+25];
            }
            if (CardsTable.size()==5)
            {
                combinationMass[0]=CardsTable[0];
                combinationMass[1]=CardsTable[1];
                combinationMass[2]=CardsTable[2];
                combinationMass[3]=CardsTable[3];
                combinationMass[4]=CardsTable[4];

            }
        }
        //получаем комбинацию у одного игрока
        player->combPlayer(combinationMass, CardPlayer1);
        combM[0]=player->returnCombaT();
        //получаем комбинацию у другого игрока
        player->combPlayer(combinationMass, CardPlayer2);
        combM[1]=player->returnCombaT();


        //определяем выиграла ли комбинация одного у другого
        if (combM[0]>combM[1]){
            value++;
        }
        if(combM[0]==combM[1]){
            if(valuePlayers[0]>valuePlayers[2])
                value++;
            if(valuePlayers[0]==valuePlayers[2])
                if(valuePlayers[1]>valuePlayers[3])
                    value++;
            // else score++;
        }


    }
    //draw=(set/score);
    persent=((value-score)/(set))*100;
    //небольшая корректировка значения

    QString Qpersent;
    Qpersent.setNum(persent);
    return Qpersent;
}


QString Pack::getCardAut(int y, int &z)
{
    return cardsAut[y].getName(z);

}
int Pack::getValueAut(int &y) //возвращает ранг карты по номеру
{
    return cardsAut[y].getCardValue();
}

int Pack::getSuitAut(int &y) //возвращает масть карты по номеру
{
    return cardsAut[y].getCardSuit();
}
QString Pack::getNameCardAut(QString &arg)
{
    int z=3; // значение
    int w=1;//полное имя
    for(int y=0;y<52;y++)
    {
        if(cardsAut[y].getName(w)==arg)
            return cardsAut[y].getName(z);
    }
}


