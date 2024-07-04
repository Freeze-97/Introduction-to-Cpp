# Project name
project(dt018g)

# Minimum required cmake version
cmake_minimum_required(VERSION 3.2)

# Compile with c++ 11 support
set(CMAKE_CXX_STANDARD 11)

# Static inclusion of dependencies required for the executable to be independent
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

# Add source directories for the project
aux_source_directory(Project/src PROJECT)
aux_source_directory(Project/include PROJECT)

# Add executables for all configurations!
add_executable(${PROJECT_NAME}-LAB_1_ASSIGNMENT_1 Laboration_1/src/Assignment_1.cpp)
add_executable(${PROJECT_NAME}-LAB_1_ASSIGNMENT_2 Laboration_1/src/Assignment_2.cpp)

add_executable(${PROJECT_NAME}-LAB_2_ASSIGNMENT_1 Laboration_2/src/Assignment_1.cpp)
add_executable(${PROJECT_NAME}-LAB_2_ASSIGNMENT_2 Laboration_2/src/Assignment_2.cpp)
add_executable(${PROJECT_NAME}-LAB_2_ASSIGNMENT_3 Laboration_2/src/Assignment_3.cpp)

add_executable(${PROJECT_NAME}-LAB_3_ASSIGNMENT_1 Laboration_3/src/Assignment_1.cpp)
add_executable(${PROJECT_NAME}-LAB_3_ASSIGNMENT_2 Laboration_3/src/Assignment_2.cpp)
add_executable(${PROJECT_NAME}-LAB_3_ASSIGNMENT_3 Laboration_3/src/Assignment_3.cpp)

add_executable(${PROJECT_NAME}-LAB_4_ASSIGNMENT_1 Laboration_4/src/Assignment_1.cpp)
add_executable(${PROJECT_NAME}-LAB_4_ASSIGNMENT_2 Laboration_4/src/Assignment_2.cpp)
add_executable(${PROJECT_NAME}-LAB_4_ASSIGNMENT_3 Laboration_4/src/Assignment_3.cpp)

add_executable(${PROJECT_NAME}-LAB_5_ASSIGNMENT_1A Laboration_5/src/Assignment_1A.cpp)
add_executable(${PROJECT_NAME}-LAB_5_ASSIGNMENT_1B Laboration_5/src/Assignment_1B.cpp)
add_executable(${PROJECT_NAME}-LAB_5_ASSIGNMENT_2 Laboration_5/src/Assignment_2.cpp)

add_executable(${PROJECT_NAME}-PROJECT ${PROJECT} Project/src/project.h Project/src/project.cpp)