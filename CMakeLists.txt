cmake_minimum_required(VERSION 3.20)

project(DeepeCam)

add_executable(DeepeCamTest
    src/main.cpp
)

add_library(DeepeCamMediaSource SHARED
    src/DeepeCamMediaSource.cpp
    src/MediaSource/DeepeCamMediaStream.cpp
    src/MediaSource/DeepeCamFactory.cpp
    src/MediaSource/DeepeCamClassFactory.cpp
    src/MediaSource/DeepeCamDll.cpp
)

target_link_libraries(DeepeCamMediaSource PRIVATE
    mfplat.lib
    mfsensorgroup.lib
)

target_include_directories(DeepeCamMediaSource PRIVATE
    src/MediaSource
)
