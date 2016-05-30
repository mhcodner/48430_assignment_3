cmake_minimum_required(VERSION 3.5)
project(assignment_3)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES advassignment.c)
add_executable(assignment_3 ${SOURCE_FILES})