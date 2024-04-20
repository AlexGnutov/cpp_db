cmake_minimum_required(VERSION 3.5)

project(hw4 LANGUAGES CXX)

if (MSVC)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


set(HEADERS
    db.h
    usermodel.h
    userphonemodel.h
    )

set(SOURCES
    db.cpp
    usermodel.cpp
    userphonemodel.cpp
    main.cpp
    )

add_executable(hw4 ${SOURCES} ${HEADERS})
target_link_libraries(hw4 libpqxx::pqxx)

add_subdirectory(libpqxx-master libpqxx-build)
