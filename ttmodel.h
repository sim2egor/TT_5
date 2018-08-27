#ifndef TTMODEL_H
#define TTMODEL_H

#include <QObject>
#include <QSqlQueryModel>

class TTModel : public QSqlQueryModel
{
    Q_OBJECT

public:
    // Перечисляем все роли, которые будут использоваться в TableView
    enum Roles {
        ID = Qt::UserRole + 1,    // record
        NOTE
    };

    // объявляем конструктор класса
    explicit TTModel(QObject *parent =nullptr);

    // Переопределяем метод, который будет возвращать данные
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    /* хешированная таблица ролей для колонок.
     * Метод используется в дебрях базового класса QAbstractItemModel,
     * от которого наследован класс QSqlQueryModel
     * */
    QHash<int, QByteArray> roleNames() const;

signals:

public slots:

};

#endif // TTMODEL_H
