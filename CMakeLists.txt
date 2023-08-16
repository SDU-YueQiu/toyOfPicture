cmake_minimum_required(VERSION 3.26)
project(toyOfPicture)

set(CMAKE_CXX_STANDARD 17)

add_executable(toyOfPicture main.cpp)

find_package(CImg CONFIG REQUIRED)
target_link_libraries(toyOfPicture PRIVATE CImg::CImg)