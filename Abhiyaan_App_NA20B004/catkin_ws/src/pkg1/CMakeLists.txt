cmake_minimum_required(VERSION 3.0.2)
project(pkg1)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package()

include_directories(
	${catkin_INCLUDE_DIRS}
)

add_executable(node1 src/node1.cpp)
target_link_libraries(node1 ${catkin_LIBRARIES})

add_executable(node2 src/node2.cpp)
target_link_libraries(node2 ${catkin_LIBRARIES})

add_executable(node3 src/node3.cpp)
target_link_libraries(node3 ${catkin_LIBRARIES})

