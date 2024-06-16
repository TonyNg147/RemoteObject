#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQmlContext>
#include "Model/Controller.h"

int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QRemoteObjectHost srcNode;
    srcNode.connectToNode(QUrl(QStringLiteral("local:replica")));
    
    Controller controller;

    controller.accquire(srcNode.acquire<UserHandlerReplica>());

    

    engine.addImportPath("qrc:/");
    engine.rootContext()->setContextProperty("controller", QVariant::fromValue(&controller));
    engine.load(QUrl("qrc:/UI/Main/Main.qml"));
    return app.exec();
}
