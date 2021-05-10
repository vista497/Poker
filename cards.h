#ifndef CARDS_H
#define CARDS_H
#include <QString>

class Cards
{

public:
    Cards();
    void SetCards();
    QString ShowRang(int &a);
    QString ShowSuit(int &a);

};

#endif // CARDS_H
