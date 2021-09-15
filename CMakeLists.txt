cmake_minimum_required(VERSION 3.16)
project(tooska
        VERSION 1.0.0
        DESCRIPTION "Any parser is a simple and lightweight parsing library that can parse documents of types html, css and json."
        )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(TOOSKA tooska CACHE INTERNAL "")

option(BUILD_TESTS "Build tests" ON)
option(BUILD_TOOLS "Build tools" ON)

set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
            STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
            "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

add_subdirectory(src)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

if(BUILD_TOOLS)
    add_subdirectory(tools)
endif()

#configure_file(${PROJECT_SOURCE_DIR}/src/global.h ${PROJECT_BINARY_DIR}/global.h COPYONLY)

include(GNUInstallDirs)

#----------------------- PKG CONFIGURATION --------------------------------
message(STATUS "Package Tooska for ${CMAKE_BUILD_TYPE} version ${PROJECT_VERSION}")
set(TARGET1 ${TOOSKA})

# Generate pkg-config file
configure_file(./tooska.pc.in ${PROJECT_BINARY_DIR}/tooska.pc @ONLY)

#----------------------- INSTALL --------------------------------
install(TARGETS ${TOOSKA} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${PROJECT_BINARY_DIR}/tooska.pc DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
