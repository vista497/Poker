#include "table.h"

Table::Table()
{
    m_player=2;
    //tableCards=new int[5];
    pack=new Pack;
    rangName=new QString[5];
    value=new int[5];

}
void Table::SetCardTable(int arg1, int x)//получаю имя карты на столе, записываю ее в массив карт на столе
{

    tableCards[x]=arg1;
}

int* Table::getCardTable()
{
        return tableCards;

}

int* Table::AutPlyer()
{

}
