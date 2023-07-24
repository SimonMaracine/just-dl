cmake_minimum_required(VERSION 3.20)

add_executable(main "main.cpp")

target_link_libraries(main PRIVATE just_dl)

set_cpp_standard(main)
