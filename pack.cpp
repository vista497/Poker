#include "pack.h"

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
    allCardOnTable=new int[52];
    closeCards=new int[52];
    openCards= new int[52];
    valueAut=new int[52];
    suitAut=new int[52];
    valueClose=new int[52];
    suitClose=new int[52];

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

QString Pack::allCardsOnTableFunc(int *allCardsTable, int* CardsPlyer, int* CardsTable)
{
    //находим длину массива
    int len=1;
    do
    {
        len++;
    }while(0<=allCardOnTable[len+1]<52);

    //помещаем карты в массив открытых карт
    for(int x=0;x<len;x++)
        openCards[x]=allCardOnTable[x];

    //получаем массив закрытых карт
    for(int x=0;x<52;x++)
        for(int y=0;y<len;y++)
        {
        if(cards[x].getid()!=openCards[y])
        closeCards[x]=cards[x].getid();
        }

    //получаем ранг карт и масть закрытых карт
    for(int x=0;x<52;x++)
    {
        for(int r=0;r<52;r++)
        {
            if(r==closeCards[x])
            {
                valueClose[x]=getValue(r);
                suitClose[x]=getSuit(r);
            }
            if(closeCards[x]==-1)
            {
                valueClose[x]=-1;
                suitClose[x]=-1;
            }
        }
    }

    //получаем ранг и масть открытых карт
    for(int x=0;x<52;x++)
    {
        for(int r=0;r<52;r++)
        {
            if(r==openCards[x])
            {
                valueOpen[x]=getValue(r);
                suitOpen[x]=getSuit(r);
            }
            if(openCards[x]==-1)
            {
                valueOpen[x]=-1;
                suitOpen[x]=-1;
            }
        }
    }
    //ищем все ауты игрока до флопа
    score=0;
    for(int x=0;x<52;x++)
        for(int y=0;y<52; y++)
        {
            if(valueOpen[x]==valueClose[y]||suitOpen[x]==suitClose[y])
            {
                if(valueOpen[x]==valueClose[y])
                {
                    valueAut[x]=valueClose[y];
                    suitAut[x]=suitClose[y];
                    score++;

                }
                if(suitOpen[x]==suitClose[y])
                {
                    valueAut[x]=valueClose[y];
                    suitAut[x]=suitClose[y];
                    score++;
                }
            }

        }

    cardsAut=new Card[score];
    int i=0;
    for (int x=0; x<4; x++)
    {
        for (int y=0; y<13; y++)
        {

            cardsAut[i++].SetCard(suitAut[x],valueAut[y]);
            NameAut+=getCardAut(x,y)+" ";
        }
    }

    //устанавливаю имена карт аутов

    return NameAut;
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


