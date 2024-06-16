cmake_minimum_required(VERSION 3.6)

project(UserHandlerSrv)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Qml Gui)

set(SOURCES
    main.cpp
    Model/Controller.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(Qml)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Qt6::Gui
        Qt6::Qml
        UI
        UserHandlerSource
)

if(WIN32)
    set_target_properties(${PROJECT_NAME}
        PROPERTIES
            WIN32_EXECUTABLE TRUE
    )
endif()
