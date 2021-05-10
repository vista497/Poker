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
    this->setWindowTitle("Poker calculator");
    values = new QList<QPair<int,QString>>();
    values->append(QPair<int,QString>(-1,"Rang"));
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
    ui_main->comboBox_6->setEnabled(false);
    ui_main->comboBox_7->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui_main;
}

void MainWindow::on_pushButton_clicked()//отправляет массив карт со стола для посчета комбинации стола, отправляет массив карт игрока
{
    ui_main->label_2->clear();
    ui_main->label_3->clear();
    QVector<int> arr;
    arr=table[1].tableCardsVector;
    if(table[2].tableCardsVector.size()==0/*||table[2].tableCardsVector.size()==0*/)
    {
        msg.setWindowTitle("Внимание!");
        msg.setText("Не заполнены поля карт игрока!");
        msg.exec();

    }else if(((table[1].tableCardsVector.size()==2||table[2].tableCardsVector.size()==0) || (table[1].tableCardsVector.size()==0||table[2].tableCardsVector.size()==2))&&(table[1].tableCardsVector.size()!=table[2].tableCardsVector.size())){
        //вывод имеющейся комбинации
        ui_main->label_3->setText(players[1].combPlayer(table[0].getCardTable(), table[2].getCardTable()));

        f.show();
        f.FormSet(table[2].tableCardsVector, table[0].tableCardsVector);
    }
    else{
        //вывод имеющейся комбинации
    ui_main->label_2->setText(players[0].combPlayer(table[0].getCardTable(), table[1].getCardTable()));
    ui_main->label_3->setText(players[1].combPlayer(table[0].getCardTable(), table[2].getCardTable()));

    //вычесление процента 1 игрока
    QString str=pack->allCardsOnTableFunc(table[3].tableCardsVector, table[1].tableCardsVector, table[0].tableCardsVector, table[2].tableCardsVector);
    ui_main->label->setText(str);
    //вычесление процента 2 игрока
    QString str1;

    str1.setNum(100-pack->persent);
    ui_main->label_4->setText(str1);

    }
    if(q1>0)
    table[1].tableCardsVector.clear();
    if(q2>0)
    table[2].tableCardsVector.clear();



}

void MainWindow::on_pushButton_2_clicked()
{
    table[0].tableCardsVector.clear();
    table[1].tableCardsVector.clear();
    table[2].tableCardsVector.clear();
   // ui_main->comboBox->
    ui_main->comboBox_2->setModel(model);
    ui_main->comboBox_3->setModel(model);
    ui_main->comboBox_4->setModel(model);
    ui_main->comboBox_5->setModel(model);
    ui_main->comboBox_6->setModel(model);
    ui_main->comboBox_7->setModel(model);
    ui_main->comboBox_8->setModel(model);
    ui_main->comboBox_9->setModel(model);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    i=0;
    int a=index-1;
    table[0].SetCardTable(a,i); //устанавливаем карту в массив открытых карт

    table[0].SetCardTableVector(a);
    table[3].SetCardTable(a,i);//все карты

    table[3].SetCardTableVector(a);//все карты


}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    i=1;
    int a=index-1;
    table[0].SetCardTable(a,i); //устанавливаем карту в массив открытых карт

    table[0].SetCardTableVector(a);
    table[3].SetCardTable(a,i);

    table[3].SetCardTableVector(a);

}

void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    i=2;
    int a=index-1;
    table[0].SetCardTable(a,i); //устанавливаем карту в массив открытых карт

    table[0].SetCardTableVector(a);
    table[3].SetCardTable(a,i);

    table[3].SetCardTableVector(a);

}

void MainWindow::on_comboBox_4_currentIndexChanged(int index)
{
    i=3;
    int a=index-1;
    table[0].SetCardTable(a,i); //устанавливаем карту в массив открытых карт

    table[0].SetCardTableVector(a);
    table[3].SetCardTable(a,i);

    table[3].SetCardTableVector(a);

}

void MainWindow::on_comboBox_5_currentIndexChanged(int index)
{
    i=4;
    int a=index-1;
    table[0].SetCardTable(a,i); //устанавливаем карту в массив открытых карт

    table[0].SetCardTableVector(a);
    table[3].SetCardTable(a,i);

    table[3].SetCardTableVector(a);

}

//карта1 игрока 1
void MainWindow::on_comboBox_6_currentIndexChanged(int index)
{
    i=0;
    j=5;

    int a=index-1;
    table[1].SetCardTable(a,i); //устанавливаем карту в массив открытых карт

    table[1].SetCardTableVector(a);

    table[3].SetCardTable(a,j);

    table[3].SetCardTableVector(a);

}

// карта2 игрока 1
void MainWindow::on_comboBox_7_currentIndexChanged(int index)
{
    i=1;
    j=6;
    int a=index-1;
    table[1].SetCardTable(a,i); //устанавливаем карту в массив открытых карт

    table[1].SetCardTableVector(a);
    table[3].SetCardTable(a,j);

    table[3].SetCardTableVector(a);

}
//карта 1 игрока 2
void MainWindow::on_comboBox_8_currentIndexChanged(int index)
{
    i=0;
    j=7;
    int a=index-1;
    table[2].SetCardTable(a,i); //устанавливаем карту в массив открытых карт

    table[2].SetCardTableVector(a);
    table[3].SetCardTable(a,j);

    table[3].SetCardTableVector(a);
}

//карта 2 игрока 2
void MainWindow::on_comboBox_9_currentIndexChanged(int index)
{
    i=1;
    j=8;
    int a=index-1;
    table[2].SetCardTable(a,i); //устанавливаем карту в массив открытых карт

    table[2].SetCardTableVector(a);
    table[3].SetCardTable(a,j);

    table[3].SetCardTableVector(a);
}


void MainWindow::on_radioButton_clicked(bool checked)
{
    ui_main->comboBox_6->setEnabled(checked);
    ui_main->comboBox_7->setEnabled(checked);
}
