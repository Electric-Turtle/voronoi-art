cmake_minimum_required(VERSION 2.8.3)
project(voronoi_art)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
set(BUILD_SHARED_LIBS true)
find_package( OpenCV REQUIRED )
find_package( Boost 1.40 COMPONENTS program_options filesystem REQUIRED )
include_directories(include)
add_library(${PROJECT_NAME}_image_processing
 src/image_processing/image_processing.cpp
)
target_link_libraries(${PROJECT_NAME}_image_processing 
 ${OpenCV_LIBS}
)
add_library(${PROJECT_NAME}_voronoi_processing
 src/voronoi_processing/voronoi_processing.cpp
)
target_link_libraries(${PROJECT_NAME}_voronoi_processing 
 ${PROJECT_NAME}_image_processing 
 ${Boost_LIBRARIES}
)

add_executable(test_program src/test_program.cpp)
target_link_libraries( test_program 
 ${PROJECT_NAME}_image_processing
 ${PROJECT_NAME}_voronoi_processing
 )
add_executable(voronoi_test src/voronoi_test.cpp)
target_link_libraries( voronoi_test 
 ${PROJECT_NAME}_image_processing
 ${PROJECT_NAME}_voronoi_processing
 )


