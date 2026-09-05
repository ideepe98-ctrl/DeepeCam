cmake_minimum_required(VERSION 3.20)

project(DeepeCamTest)

add_executable(DeepeCamTest
    src/main.cpp
)

target_link_libraries(DeepeCamTest PRIVATE
    mfplat.lib
    mfsensorgroup.lib
)
