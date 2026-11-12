cmake_minimum_required(VERSION 3.22.1)
project("pokegen3")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ENGINE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../../engine")

include_directories(
    "${ENGINE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

add_library(
    pokegen3
    SHARED
    "${ENGINE_DIR}/src/bus.cpp"
    "${ENGINE_DIR}/src/cpu.cpp"
    "${ENGINE_DIR}/src/ppu.cpp"
    "${ENGINE_DIR}/src/apu.cpp"
    "${ENGINE_DIR}/src/transit.cpp"
    "${ENGINE_DIR}/src/qol.cpp"
    "${ENGINE_DIR}/src/carousel.cpp"
    "${ENGINE_DIR}/src/pokegen3.cpp"
    "jni_bridge.cpp"
)

find_library(log-lib log)
find_library(android-lib android)
find_library(gles-lib GLESv3)
find_library(egl-lib EGL)
find_library(aaudio-lib aaudio)

target_link_libraries(
    pokegen3
    ${log-lib}
    ${android-lib}
    ${gles-lib}
    ${egl-lib}
    ${aaudio-lib}
)
