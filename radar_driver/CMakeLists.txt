cmake_minimum_required(VERSION 2.8.3)
project(radar_driver)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED
  COMPONENTS
    can_msgs
    roscpp
    socketcan_interface
    pb_msgs
    geometry_msgs
    sensor_msgs
)

catkin_package(
  INCLUDE_DIRS
    include
  LIBRARIES
    decode
    decode_cluster
    warning
    speed_info
    configuration
  CATKIN_DEPENDS
    can_msgs
    roscpp
    socketcan_interface
    pb_msgs
    geometry_msgs
    sensor_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# decode 
add_library(decode
  src/decode.cpp
)
target_link_libraries(decode
  ${catkin_LIBRARIES}
)
add_dependencies(decode
  ${catkin_EXPORTED_TARGETS}
)

# decode_cluster
add_library(decode_cluster
  src/decode_cluster.cpp
)
target_link_libraries(decode_cluster
  ${catkin_LIBRARIES}
)
add_dependencies(decode_cluster
  ${catkin_EXPORTED_TARGETS}
)

# warning
add_library(warning
  src/warning.cpp
)
target_link_libraries(warning
  ${catkin_LIBRARIES}
)
add_dependencies(warning
  ${catkin_EXPORTED_TARGETS}
)

# speed_info
add_library(speed_info
  src/speed_info.cpp
)
target_link_libraries(speed_info
  ${catkin_LIBRARIES}
)
add_dependencies(speed_info
  ${catkin_EXPORTED_TARGETS}
)

# configuration
add_library(configuration
  src/configuration.cpp
)
target_link_libraries(configuration
  ${catkin_LIBRARIES}
)
add_dependencies(configuration
  ${catkin_EXPORTED_TARGETS}
)

# decode_node
add_executable(decode_node
  src/decode_node.cpp
)
target_link_libraries(decode_node
  decode
  ${catkin_LIBRARIES}
)

# decode_node_cluster
add_executable(decode_node_cluster
  src/decode_node_cluster.cpp
)
target_link_libraries(decode_node_cluster
  decode_cluster
  ${catkin_LIBRARIES}
)

# warning_node
add_executable(warning_node
  src/warning_node.cpp
)
target_link_libraries(warning_node
  warning
  ${catkin_LIBRARIES}
)

# speed_info_node
add_executable(speed_info_node
  src/speed_info_node.cpp

)
target_link_libraries(speed_info_node
  speed_info
  ${catkin_LIBRARIES}
)


# configuration_node
add_executable(configuration_node
  src/configuration_node.cpp

)
target_link_libraries(configuration_node
  configuration
  ${catkin_LIBRARIES}
)
