#ifndef QCOMBOBOXMODEL_H
#define QCOMBOBOXMODEL_H

#include <QModelIndex>

class QComboBoxModel : public QAbstractListModel
{
public:
    QComboBoxModel(QObject *parent=nullptr);
    int rowCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;
    void populate(QList<QPair<int,QString>> *newValues);
    void SetTextBox(QString *newValues);
private:
    QList<QPair<int,QString>> *values;
    QString* str;
};

#endif // QCOMBOBOXMODEL_H
