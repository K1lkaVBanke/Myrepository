#include <ros/ros.h>
#include <pb_msgs/ContiRadar.h>
#include <pb_msgs/ContiList.h>
#include <sensor_msgs/PointCloud2.h>

#include <radar_pointcloud/radar_pointcloud.h>

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "radar_pointcloud_node");

  // Create an object of class RadarPointCloudTransformation
  radar_pointcloud::RadarPointCloudTransformation TransfObject;

  ros::spin();

  return 0;
}

