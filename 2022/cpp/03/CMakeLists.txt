cmake_minimum_required(VERSION 3.19)
project(main)
# add_subdirectory(include/fmt)
configure_file(input.txt input.txt COPYONLY)
add_executable(main main.cc)
target_link_libraries(main) 