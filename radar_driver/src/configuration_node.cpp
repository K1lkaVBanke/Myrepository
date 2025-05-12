#include <ros/ros.h>
#include "std_msgs/String.h"
#include <can_msgs/Frame.h>

#include <radar_driver/configuration.h>
#include <radar_driver/configuration_vars.h>

int main(int argc, char **argv)
{
  	//Initiate ROS
  	ros::init(argc, argv, "configuration_node");

  	//Create an object of class ConfigurationNode that will take care of everything
  	radar_driver::ConfigurationNode ConfigurationObject;

  	radar_driver::FilterConfigurationNode FilterObject;

  	radar_driver::CollisionConfigurationNode CollisionObject;

  	radar_driver::CollisionRegionConfigurationNode RegionObject;
  	
  	sleep(8);

  	ros::spinOnce();

  	return 0;
}
