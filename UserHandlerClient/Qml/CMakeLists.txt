add_library(UIClient STATIC)

qt6_add_qml_module(UIClient
    URI UI.Main
    VERSION 1.0
    QML_FILES Main.qml
    NO_PLUGIN
    RESOURCES  qmldir
)



