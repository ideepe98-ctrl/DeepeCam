cmake_minimum_required(VERSION 3.20)

project(DeepeCamTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DeepeCamTest
    src/main.cpp
)

if(MSVC)
    target_compile_options(DeepeCamTest PRIVATE /W4 /O2)
endif()
