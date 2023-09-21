cmake_minimum_required(VERSION "3.25.1")

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(raytracer)
set(CMAKE_CXX_STANDARD 20)
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(raytracer "${MY_SOURCES}")
target_include_directories(raytracer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/headers/")
