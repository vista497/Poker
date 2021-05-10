#ifndef FORM_H
#define FORM_H

#include <QWidget>

#include <QVector>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    void Percent(QVector<int> Cards,QVector<int> Table);
    QString a, b, c,d,e,f,g,k,l;
    void FormSet(QVector<int> Cards, QVector<int> Table);
       QString str;
        QVector<int>closeCardsVector;
        QVector<int>openCardsVector;

private:
    Ui::Form *ui;
};

#endif // FORM_H
