#include "cards.h"

Cards::Cards()
{
    SetCards();
}
void Cards::SetCards()
{
   m_card_suit[0]="Крести";
   m_card_suit[1]="Пики";
   m_card_suit[2]="Буби";
   m_card_suit[3]="Черви";

   m_rang[0]="2";
   m_rang[1]="3";
   m_rang[2]="4";
   m_rang[3]="5";
   m_rang[4]="6";
   m_rang[5]="7";
   m_rang[6]="8";
   m_rang[7]="9";
   m_rang[8]="10";
   m_rang[9]="Валет";
   m_rang[10]="Дама";
   m_rang[11]="Король";
   m_rang[12]="Туз";
}

QString Cards::ShowRang(int &a)
{
    return m_rang[a];
}

QString Cards::ShowSuit(int &a)
{
    return m_card_suit[a];
}
