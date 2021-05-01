cmake_minimum_required(VERSION 3.0.2)
project(turtle)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  message_generation
  roscpp
  std_msgs
)


catkin_package(

)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(turtle_node1 src/turtle_node1.cpp)
target_link_libraries (turtle_node1 ${catkin_LIBRARIES})



