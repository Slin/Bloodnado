cmake_minimum_required(VERSION 3.3)
project(Bloodnado)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Bloodnado ${SOURCE_FILES})

find_package(ITK REQUIRED)
find_package(VTK REQUIRED)
include(${ITK_USE_FILE} ${VTK_USE_FILE})
target_link_libraries(Bloodnado ${VTK_LIBRARIES} ${ITK_LIBRARIES})
