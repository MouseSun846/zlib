cmake_minimum_required(VERSION 3.4.1)
#给项目命名
PROJECT(mas C CXX)
SET(CMAKE_BUILD_TYPE Debug)
message(status ${CMAKE_BUILD_TYPE})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/lib)



# Add an executable
add_executable(mas ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_link_libraries(mas z minizip)