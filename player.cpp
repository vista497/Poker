#include "player.h"
#include "algorithm"

Player::Player()
{
    PlayerName="";
    pack=new Pack;
    rangName=new QString[5];
    value=new int[7];
    valueR=new int[7];
    suit=new int[7];
}
void Player::SetPlayer(QString cardName, QString playerName)
{
    PlayerName= playerName;
}

QString Player::combPlayer(int* tableCards, int* playerCards)
{
    int w=3;
    int a=7;
    combT="";

    for (int i=0; i<5; i++)
    {
        valueR[i] = tableCards[i];
    }
    for (int i=5; i<7; i++)
    {
        valueR[i] = playerCards[i - 5];
    }




    //получаем ранг карт и масть со стола
    for(int x=0;x<a;x++)
    {
        for(int r=0;r<52;r++)
        {
            if(r==valueR[x])
            {
                value[x]=pack->getValue(r);
                suit[x]=pack->getSuit(r);
            }
            if(valueR[x]==-1)
            {
                value[x]=-1;
                suit[x]=-1;
            }
        }
    }

    //проверка на одинаковые карты

//    for(int x=0;x<a;x++)
//    {
//        for(int y=0;y<a;y++)
//        {
//            if(x!=y && value[y]==value[x] && value[y]!=-1 && suit[y]==suit[x] )
//            {
//                msg.setWindowTitle("Внимание");
//                msg.setText("Найдены одниковые карты");
//                msg.exec();

//            }
//        }
//    }
    //сортируем
    for(int x=0;x<a;x++)
        for(int y=0;y<a-x;y++)
            if(value[y]>value[y+1] &&y<a-1)
            {
                int v=value[y];
                value[y]=value[y+1];
                value[y+1]=v;

                if(suit[y]>suit[y+1] && y<a-1)
                {
                    int s=suit[y];
                    suit[y]=suit[y+1];
                    suit[y+1]=s;
                }
            }



    //поиск комбинации
    for(int x=0;x<a;x++)
        for(int y=0;y<a;y++)
            if(value[y]<value[y+1]&&y!=a-1)
            {
                combT="Старшая карта:";
                combaT=0;
                rangMaxT=rangMaxT=pack->getCard(value[y+1],w);

            }


    for(int x=0; x<a;x++)
    {
        for(int y=0;y<a;y++)
        {
            if(value[x]==value[y] && value[y]!=-1 &&x!=y && combaT!=6)
            {
                combT="Пара";
                combaT=1;
                rangMaxT=pack->getCard(value[y],w);

                for(int z=0;z<a;z++)
                {
                    if(value[y]==value[z]&&y!=z && z!=x)
                    {
                        combaT=3;
                        combT="Тройка";
                        rangMaxT=pack->getCard(value[z],w);
                        break;
                        for(int z=0;z<a;z++)
                        {
                            for(int i=0;i<5;i++)
                            {
                                if(value[z]==value[i]&&y!=z && z!=x && i!=x &&  i!=y && value[i]!=-1 && z!=i)
                                {
                                    combT="Фул хаус";
                                    combaT=6;
                                    rangMaxT=pack->getCard(value[i],w);
                                }
                            }
                        }
                    }
                }
                for(int z=0;z<a;z++)
                {
                    for(int i=0;i<5;i++)
                    {
                        if(value[z]==value[i]&&y!=z && z!=x && i!=x &&  i!=y && value[i]!=-1 && z!=i && combaT!=6)
                        {
                            combT="Две пары";
                            combaT=2;
                            rangMaxT=pack->getCard(value[i],w)+" "+pack->getCard(value[x],w);

                            for(int h=0;h<a;h++)
                            {
                                if(value[h]==value[i] && value[i]!=value[x] &&h!=z && z!=x && h!=x &&  h!=y && h!=i)
                                {
                                    combT="Фул Хаус";
                                    combaT=6;
                                    rangMaxT=pack->getCard(value[i],w);
                                    break;
                                }
                            }
                            if(value[x]==value[i])
                            {
                                combT="Каре";
                                combaT=7;
                                rangMaxT=pack->getCard(value[x],w);
                                break;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }



    //ищем флеш
    if(combaT!=6 && combaT!=7)
    {
        flesh=0;
        for(int y=0;y<a;y++)
            if(suit[y]==suit[y+1] && suit[y]!=-1&& y!=a-1)
            {
                flesh++;
            }
        if (flesh>=4)
        {
            combT="Флеш";
            combaT=5;
            rangMaxT=pack->getCard(value[a-1],w);
        }
    }

    //ищем стрит
    strit=0;
    for(int y=0;y<a;y++)
    {
        if(value[y]+1==value[y+1]&&value[y]!=-1)
        {
            strit++;
        }
    }
    if ((strit>=4))
    {
        combT="Стрит";
        combaT=4;
        rangMaxT=pack->getCard(value[a-1],w);
        flesh=0;
        for(int y=0;y<a;y++)
        {
            if(suit[y]==suit[y+1] && suit[y]!=-1&& y!=a-1)
            {
                flesh++;
            }
            if (flesh>=4)
            {
                combT="Стрит флеш";
                combaT=8;
                rangMaxT=pack->getCard(value[a-1],w);
            }
            if (flesh>=4 && value[a-1]==12)
            {
                combT="Флеш рояль";
                combaT=9;
                rangMaxT=pack->getCard(12,w);
            }
        }
    }
    //стрит от туза до 5
    if(strit>=3 && value[a-1]==12 && value[0]==0)
    {
        combT="Стрит";
        combaT=4;
        rangMaxT=pack->getCard(3,w);
        flesh=0;
        for(int y=0;y<a;y++)
        {
            if(suit[y]==suit[y+1] && suit[y]!=-1&& y!=a-1)
            {
                flesh++;
            }
            if (flesh>=4)
            {
                combT="Стрит флеш";
                combaT=8;
                rangMaxT=pack->getCard(3,w);
            }
        }


    }
    combwithMaxrang=combT+" "+rangMaxT;
    return combwithMaxrang;
}

int Player::returnCombaT(){
    return combaT;

}



