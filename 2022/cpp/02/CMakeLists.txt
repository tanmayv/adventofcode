cmake_minimum_required(VERSION 3.19)
project(main)
if (NOT MY_VALUE)
    SET(MY_VALUE default)
endif()
message(${MY_VALUE})
# add_subdirectory(include/fmt)
configure_file(input.txt input.txt COPYONLY)
add_executable(main main.cc)
target_link_libraries(main fmt)