#include <ros/ros.h>
#include "std_msgs/String.h"
#include <can_msgs/Frame.h>
#include <geometry_msgs/Point32.h>
#include <radar_driver/speed_info.h>

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "speed_info_node");

  //Create an object of class SpeedinfoNode that will take care of everything
  radar_driver::SpeedinfoNode SpeedObject;

  //Create an object of class YawinfoNode that will take care of everything
  radar_driver::YawinfoNode YawObject;
  
  ros::spin();

  return 0;
}

