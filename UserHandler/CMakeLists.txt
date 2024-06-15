cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 REQUIRED COMPONENTS Core RemoteObjects)

add_library(UserHandlerSource STATIC)

qt6_add_repc_sources

target_sources(UserHandlerSource
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/UserHandler_Source/UserHandlerSrc.h
)

target_link_libraries(UserHandlerSource
    PUBLIC
        Qt6::Core
        Qt6::RemoteObjects
)

target_include_directories(UserHandlerSource
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/UserHandler_Source
        ${CMAKE_BINARY_SOURCE_DIR}
)

set_target_properties(UserHandlerSource
    PROPERTIES
        LINKER_LANGUAGE CXX
)