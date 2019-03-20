#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "initdb.h"
#include "ttmodel.h"

#include <QtSql>
#include <QApplication>
#include <QQmlContext>

// edit2
int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    // DB init
    //DataBase database;
    if (!QSqlDatabase::drivers().contains("QSQLITE"))
        qDebug() <<"error open DB";
    // Initialize the database:
    QSqlError err = initDb();
    if (err.type() != QSqlError::NoError) {
        qDebug() <<"error open DB";
        return -1;
    }
    //model
    TTModel ttmodel;
    ttmodel.setQuery("select  id , note FROM  notes ;");
    engine.rootContext()->setContextProperty("myModel", &ttmodel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
