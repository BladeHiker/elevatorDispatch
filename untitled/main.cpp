#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Dispatch.h"
#include "unistd.h"
#include "time.h"
#include "Working.h"
#include "elevatordata.h"
#include <QQmlContext>
int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    qmlRegisterType<Working>("Working", 1, 0, "Working");
     qmlRegisterType<ElevatorData>("ElevatorData",1,0,"ElevatorData");

    QQmlContext* rootContex = engine.rootContext();
    QList<ElevatorData*> elevatorDataList;
       for(int i=0;i<4;++i)elevatorDataList.append(new ElevatorData());
       rootContex->setContextProperty("ele0",elevatorDataList[0]);
       rootContex->setContextProperty("ele1",elevatorDataList[1]);
       rootContex->setContextProperty("ele2",elevatorDataList[2]);
       rootContex->setContextProperty("ele3",elevatorDataList[3]);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
