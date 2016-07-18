add_executable(example example.cpp)
target_include_directories(example PUBLIC ../../src/)
target_link_libraries(libhpxflow)
target_compile_options(example PUBLIC -std=c++11 -Wall -Wfloat-conversion)
