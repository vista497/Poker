#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_main(new Ui::MainWindow)


{
    pack=new Pack;
    table=new Table[4];

    str=new QString[10];
    cardsOpen=new Card[7];
    players=new Player[2];

    int w=1;


   ui_main->setupUi(this);

   values = new QList<QPair<int,QString>>();
   values->append(QPair<int,QString>(99,"Rang"));
   for(int y=0; y<52;y++)
   {

       values->append(QPair<int,QString>(y,pack->getCard(y,w)));
   }

   model = new QComboBoxModel[7];

    model->populate(values);

    this->ui_main->comboBox->setModel(model);
    this->ui_main->comboBox_2->setModel(model);
    this->ui_main->comboBox_3->setModel(model);
    this->ui_main->comboBox_4->setModel(model);
    this->ui_main->comboBox_5->setModel(model);
    this->ui_main->comboBox_6->setModel(model);
    this->ui_main->comboBox_7->setModel(model);
    this->ui_main->comboBox_8->setModel(model);
    this->ui_main->comboBox_9->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui_main;
}

Card MainWindow::on_comboBox_activated(const QString &arg1)
{
    combobox1=arg1;
       for(int x=0; x<52; x++)
       {

          if(combobox1==pack->getCard(x,w))

              return pack->cards[x];
       }
}


void MainWindow::on_pushButton_clicked()//отправляет массив карт со стола для посчета комбинации стола, отправляет массив карт игрока
{
    ui_main->label_2->clear();
    ui_main->label_3->clear();
    ui_main->label_2->setText(players[0].combPlayer(table[0].getCardTable(), table[1].getCardTable()));
    ui_main->label_3->setText(players[1].combPlayer(table[0].getCardTable(), table[2].getCardTable()));
    pack->allCardsOnTableFunc(table[3].getCardTable(), table[0].getCardTable(), table[1].getCardTable());

    //показать все ауты(нихура не работает
   // ui_main->label_4->setText(pack->allCardsOnTableFunc(table[3].getCardTable(), table[0].getCardTable(), table[1].getCardTable()));
}

void MainWindow::on_pushButton_2_clicked()
{
        ui_main->label_2->clear();
            ui_main->label->clear();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    i=0;
    int a=index-1;
    table[0].SetCardTable(a,i); //устанавливаем карту в массив открытых карт
    table[3].SetCardTable(a,i);
    //ui_main->textEdit->setText(pack->getCard(a,w));


}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    i=1;
    int a=index-1;
    table[0].SetCardTable(a,i); //устанавливаем карту в массив открытых карт
    table[3].SetCardTable(a,i);
       // ui_main->textEdit_2->setText(pack->getCard(a,w));
}

void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    i=2;
    int a=index-1;
    table[0].SetCardTable(a,i); //устанавливаем карту в массив открытых карт
    table[3].SetCardTable(a,i);
   // ui_main->textEdit_3->setText(pack->getCard(a,w));
}

void MainWindow::on_comboBox_4_currentIndexChanged(int index)
{
    i=3;
    int a=index-1;
    table[0].SetCardTable(a,i); //устанавливаем карту в массив открытых карт
    table[3].SetCardTable(a,i);
   // ui_main->textEdit_4->setText(pack->getCard(a,w));
}

void MainWindow::on_comboBox_5_currentIndexChanged(int index)
{
    i=4;
    int a=index-1;
    table[0].SetCardTable(a,i); //устанавливаем карту в массив открытых карт
    table[3].SetCardTable(a,i);
   // ui_main->textEdit_5->setText(pack->getCard(a,w));
}

//карта1 игрока 1
void MainWindow::on_comboBox_6_currentIndexChanged(int index)
{
    i=0;
    j=5;
    int a=index-1;
    table[1].SetCardTable(a,i); //устанавливаем карту в массив открытых карт
    table[3].SetCardTable(j,i);

}

// карта2 игрока 1
void MainWindow::on_comboBox_7_currentIndexChanged(int index)
{
    i=1;
    j=6;
    int a=index-1;
    table[1].SetCardTable(a,i); //устанавливаем карту в массив открытых карт
    table[3].SetCardTable(j,i);

}
//карта 1 игрока 2
void MainWindow::on_comboBox_8_currentIndexChanged(int index)
{
    i=0;
    j=7;
    int a=index-1;
    table[2].SetCardTable(a,i); //устанавливаем карту в массив открытых карт
    table[3].SetCardTable(j,i);
}

//карта 2 игрока 2
void MainWindow::on_comboBox_9_currentIndexChanged(int index)
{
    i=1;
    j=8;
    int a=index-1;
    table[2].SetCardTable(a,i); //устанавливаем карту в массив открытых карт
    table[3].SetCardTable(j,i);
}
