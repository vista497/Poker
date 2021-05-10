#include "form.h"
//#include "table.h"
#include "ui_form.h"
//#include <QString>
//#include "algorithm"
#include "random"
#include "player.h"

Form::Form( QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setWindowTitle("Percentages of combinations");

}
void Form::FormSet(QVector<int> Cards,QVector<int> Table){

    str="Флеш рояль: %1 \n"
        "Стрит флеш: %2\n"
        "Каре: %3\n"
        "Фул хаус: %4\n"
        "Флеш: %5\n"
        "Стрит: %6\n"
        "Тройка: %7\n"
        "Две пары: %8\n"
        "Пара: %9\n";


    Percent(Cards, Table);
    ui->label->setText(str.arg(a).arg(b).arg(c).arg(d).arg(e).arg(f).arg(g).arg(k).arg(l));

}

Form::~Form()
{
    delete ui;
}

void Form::Percent(QVector<int> Cards, QVector<int> Table){

    //находим длину массива
    Player *player=new Player();

    openCardsVector=Cards+Table;
    int len=openCardsVector.size();


    //получаем массив закрытых карт
    for(int x=0;x<52;x++)
             closeCardsVector.push_back(x);

    for(int x=0; x<len;x++)
       closeCardsVector.erase(closeCardsVector.begin()+openCardsVector[x]);

    int CardM[2];
    CardM[0]=Cards[0];
    CardM[1]=Cards[1];
    double comb1=0;
    double comb2=0;
    double comb3=0;
    double comb4=0;
    double comb5=0;
    double comb6=0;
    double comb7=0;
    double comb8=0;
    double comb9=0;

    double set=10000;
    qApp->processEvents();
    for (int x=0;x<set;x++){


            int combinationMass[5];
            for(int y=0; y<5;y++){
                for(int x=0;x<2;x++)
                    std::random_shuffle(closeCardsVector.begin(), closeCardsVector.end());

                if (Table.size()<3)
                    combinationMass[y]=closeCardsVector[y+25];


                if (Table.size()==3)
                {
                    combinationMass[0]=Table[0];
                    combinationMass[1]=Table[1];
                    combinationMass[2]=Table[2];
                    if (y==3)
                        combinationMass[y]=closeCardsVector[y+25];
                }
                if (Table.size()==4)
                {
                    combinationMass[0]=Table[0];
                    combinationMass[1]=Table[1];
                    combinationMass[2]=Table[2];
                    combinationMass[3]=Table[3];
                    if (y==4)
                        combinationMass[y]=closeCardsVector[y+25];
                }
                if (Table.size()==5)
                {
                    combinationMass[0]=Table[0];
                    combinationMass[1]=Table[1];
                    combinationMass[2]=Table[2];
                    combinationMass[3]=Table[3];
                    combinationMass[4]=Table[4];

                }
            }
            //получаем комбинацию после рандома карт
            player->combPlayer(combinationMass, CardM);

            if (player->returnCombaT()==1)
            comb1++;
            if (player->returnCombaT()==2)
            comb2++;
            if (player->returnCombaT()==3)
            comb3++;
            if (player->returnCombaT()==4)
            comb4++;
            if (player->returnCombaT()==5)
            comb5++;
            if (player->returnCombaT()==6)
            comb6++;
            if (player->returnCombaT()==7)
            comb7++;
            if (player->returnCombaT()==8)
            comb8++;
            if (player->returnCombaT()==9)
            comb9++;
}
    a.setNum((comb9/set)*100);
    b.setNum((comb8/set)*100);
    c.setNum((comb7/set)*100);
    d.setNum((comb6/set)*100);
    e.setNum((comb5/set)*100);
    f.setNum((comb4/set)*100);
    g.setNum((comb3/set)*100);
    k.setNum((comb2/set)*100);
    l.setNum((comb1/set)*100);


}
