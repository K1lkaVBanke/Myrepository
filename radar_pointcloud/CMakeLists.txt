cmake_minimum_required(VERSION 2.8.3)
project(radar_pointcloud)

add_compile_options(-std=c++14)

find_package(catkin REQUIRED
  COMPONENTS
    can_msgs
    roscpp
    socketcan_interface
    pb_msgs
    geometry_msgs
    sensor_msgs
    pcl_ros
)

catkin_package(
  INCLUDE_DIRS
    include
  LIBRARIES
    radar_pointcloud
  CATKIN_DEPENDS
    can_msgs
    roscpp
    socketcan_interface
    pb_msgs
    geometry_msgs
    sensor_msgs
    pcl_ros
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)


# radar_pointcloud 
add_library(radar_pointcloud
  src/radar_pointcloud.cpp
)
target_link_libraries(radar_pointcloud
  ${catkin_LIBRARIES}
)
add_dependencies(radar_pointcloud
  ${catkin_EXPORTED_TARGETS}
)

add_executable(radar_pointcloud_node
  src/radar_pointcloud_node.cpp
)
target_link_libraries(radar_pointcloud_node
  radar_pointcloud
  ${catkin_LIBRARIES}
)

