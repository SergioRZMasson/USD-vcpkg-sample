cmake_minimum_required(VERSION 3.0.0)

project(OpenUSDPlayground VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(pxr CONFIG REQUIRED)
add_executable(OpenUSDPlayground main.cpp)

target_link_libraries(OpenUSDPlayground PRIVATE usd usdGeom)
target_compile_definitions(OpenUSDPlayground PRIVATE -DNOMINMAX)