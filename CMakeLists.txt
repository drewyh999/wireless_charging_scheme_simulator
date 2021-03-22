cmake_minimum_required(VERSION 3.16)
set(PROJECT_NAME wireless_charging_scheme_simulator)
project(${PROJECT_NAME} VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(Metrics)
include_directories(Metrics)
add_executable(wireless_charging_scheme_simulator main.cpp GraphComponents/Graph.cpp GraphComponents/Graph.h GraphComponents/vertex.cpp GraphComponents/vertex.h GraphComponents/LineFormula.cpp GraphComponents/LineFormula.h GraphComponents/point.cpp GraphComponents/point.h)
target_link_libraries(${PROJECT_NAME} PUBLIC Metrics)
