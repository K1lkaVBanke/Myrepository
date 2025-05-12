#include <ros/ros.h>
#include <std_msgs/String.h>
#include <can_msgs/Frame.h>
#include <pb_msgs/ContiRadar.h>
#include <pb_msgs/ContiList.h>
#include <radar_driver/warning.h>

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "warning_node");

  //Create an object of class WarningNode that will take care of everything
  radar_driver::WarningNode WarningObject;

  ros::spin();

  return 0;
}
