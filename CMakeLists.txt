cmake_minimum_required(VERSION 3.16.3)
project(Tarea2Geometria)
set(CMAKE_CXX_STANDARD 23)


add_subdirectory(src)
add_subdirectory(test)

add_executable(
        algoritmo
        main.cpp
)

target_link_libraries(algoritmo midPointDisplacement2D Aux_funcs)
target_include_directories(Aux_funcs PUBLIC /include)