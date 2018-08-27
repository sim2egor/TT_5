#include "ttmodel.h"

#include <QObject>
#include <QSqlQueryModel>

TTModel::TTModel(QObject *parent) :
    QSqlQueryModel(parent)
{
    // Конструктор будет пустой ;-)
}
// Метод для получения данных из модели
QVariant TTModel::data(const QModelIndex & index, int role) const {

    // Определяем номер колонки, адрес так сказать, по номеру роли
    int columnId = role - Qt::UserRole-1 ;
    // Создаём индекс с помощью новоиспечённого ID колонки
    QModelIndex modelIndex = this->index(index.row(), columnId);
    QVariant value =QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
    /* И с помощью уже метода data() базового класса
     * вытаскиваем данные для таблицы из модели
     * */
    if (columnId == 0) {
        return value.toString().prepend('#');
    }

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

// Метод для получения имен ролей через хешированную таблицу.
QHash<int, QByteArray> TTModel::roleNames() const {
    /* То есть сохраняем в хеш-таблицу названия ролей
     * по их номеру
     * */
    QHash<int, QByteArray> roles;
    roles[ID] = "ID";
    roles[NOTE] = "note";
    return roles;
}
