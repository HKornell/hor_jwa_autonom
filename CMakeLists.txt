cmake_minimum_required(VERSION 3.8)
project(light_control_pkg)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

set(ament_dependencies
  rclcpp
  std_msgs
  geometry_msgs
)

add_executable(light_sensor_node src/light_sensor_node.cpp)
ament_target_dependencies(light_sensor_node ${ament_dependencies})

add_executable(headlight_controller_node src/headlight_controller_node.cpp)
ament_target_dependencies(headlight_controller_node ${ament_dependencies})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

install(TARGETS
# simple_sub_node
DESTINATION lib/${PROJECT_NAME})

ament_package()