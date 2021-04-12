#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLayout>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>
//#include "card.h"
#include "table.h"
#include "pack.h"
#include <QString>
#include <QComboBox>
#include "qcomboboxmodel.h"
#include <QLabel>
#include <QDebug>
#include "player.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Pack* pack;
    Table* table;
    Player* players;
    Card* cardsOpen;
    QString dataSuit;
    QString dataRang;
        int w=1;
        int i=0;
        int j=0;
        int h[5];

        QList<QPair<int,QString>> *values;
        QComboBoxModel *model;
        QString* str;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString combobox1;
signals:
   int combobox();

private slots:

    Card on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_comboBox_4_currentIndexChanged(int index);

    void on_comboBox_5_currentIndexChanged(int index);

    void on_comboBox_6_currentIndexChanged(int index);

    void on_comboBox_7_currentIndexChanged(int index);

    void on_comboBox_8_currentIndexChanged(int index);



    void on_comboBox_9_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui_main;
};
#endif // MAINWINDOW_H
