add_executable(
        aux_func_test
        aux_funcs_test.cpp
)

target_link_libraries(aux_func_test midPointDisplacement2D Aux_funcs)
target_include_directories(Aux_funcs PUBLIC ../include)

add_executable(
        testing
        testing.cpp
)

target_link_libraries(testing midPointDisplacement2D Aux_funcs)
target_include_directories(Aux_funcs PUBLIC ../include)