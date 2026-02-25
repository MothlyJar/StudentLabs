cmake_minimum_required(VERSION 3.15) 

set(PROJECT_NAME main_exec) 			
project(${PROJECT_NAME})     
set(CMAKE_CXX_STANDARD 20)			

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(main_exec PRIVATE ${CMAKE_SOURCE_DIR}/Cattle)
target_link_libraries(${PROJECT_NAME} PRIVATE Cattle)
