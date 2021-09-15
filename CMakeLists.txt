cmake_minimum_required(VERSION 3.16)
project(tooska
        VERSION 1.0.0
        DESCRIPTION "Any parser is a simple and lightweight parsing library that can parse documents of types html, css and json."
        )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" ON)

add_subdirectory(src)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_subdirectory(tools)
