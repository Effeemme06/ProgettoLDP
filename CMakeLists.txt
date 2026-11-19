cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)
project(CalcoloMinimo)

include_directories(include)

add_library(${PROJECT_NAME} SHARED 
    src/Function.cpp
    src/Minimum.cpp
    src/IOminimum.cpp)

add_executable(programma
    src/main.cpp
)

target_link_libraries(programma PRIVATE ${PROJECT_NAME})


# Copia automaticamente Funtions.csv nella cartella di compilazione
# così l'eseguibile lo trova quando lo avvii da lì
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Funtions.csv
    ${CMAKE_CURRENT_BINARY_DIR}/src/Funtions.csv
    COPYONLY
)