#include "qcomboboxmodel.h"

QComboBoxModel::QComboBoxModel(QObject *parent)
    :QAbstractListModel(parent)
{
    values = new QList<QPair<int,QString>>();
    str=new QString;
}

int QComboBoxModel::rowCount(const QModelIndex &) const
{
    return values->count();
}

QVariant QComboBoxModel::data( const QModelIndex &index, int role ) const
{

    QVariant value;

        switch ( role )
        {
            case Qt::DisplayRole: //string
            {
                value = this->values->value(index.row()).second;
            }
            break;

            case Qt::UserRole: //data
            {
            value = this->values->value(index.row()).first;
            }
            break;

            default:
                break;
        }

    return value;
}

void QComboBoxModel::populate(QList<QPair<int,QString>> *newValues)
{
    int idx = this->values->count();
    this->beginInsertRows(QModelIndex(), 1, idx);
        this->values = newValues;
    endInsertRows();
 }
void QComboBoxModel::SetTextBox(QString *newValues)
{
    int idx = this->str->count();
    this->beginInsertRows(QModelIndex(), 1, idx);
        this->str = newValues;
    endInsertRows();
}
