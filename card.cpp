#include "card.h"

Card::Card(int &x, int &y)
{
    m_value=x; m_suit=y; name="";
   // SetCard(x, y);
}

QString Card::SetCard(int &x, int &y)
{
    m_suit=x;
    m_value=y;
    id++;
    if (y<9)
        m_str_value=m_str_value.setNum(y+2);
    else if (y==9)
        m_str_value="Валет";
    else if(y==10)
        m_str_value="Дама";
    else if(y==11)
        m_str_value="Король";
    else if(y==12)
       { m_str_value="Туз";}

        if(x==0)
            m_str_suit=" Крести";
        else if (x==1)
            m_str_suit=" Пики";
        else if (x==2)
            m_str_suit=" Черви";
        else if(x==3)
            m_str_suit=" Буби";
        name=m_str_value+m_str_suit;
}


int Card::getCardValue() //возвращает ранг карты
{
    return m_value;
}

int Card::getCardSuit()
{
    return m_suit;
}

int Card::getid()
{
    return id;
}
QString Card::getName(int &arg)
{
    if(arg==1)
        return name;
    if(arg==2)
        return m_str_suit;
    if (arg==3)
        return m_str_value;


}

//Card Card::operator=(Card &arg1)
//{
//    m_value=arg1.m_value;
//    m_suit=arg1.m_suit;
//    return *this;
//}
