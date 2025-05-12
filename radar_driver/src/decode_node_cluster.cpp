#include <ros/ros.h>
#include <std_msgs/String.h>
#include <can_msgs/Frame.h>
#include <pb_msgs/ClusterRadar.h>
#include <pb_msgs/ClusterList.h>
#include <radar_driver/decode_cluster.h>

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "decode_node_cluster");

  //Create an object of class DecodeCanMessageClusterNode that will take care of everything
  radar_driver::DecodeCanMessageClusterNode SAPTarget1;

  //Create an object of class ListCanMessageClusterNode that will take care of everything
  radar_driver::ListCanMessageClusterNode SAPTarget2;

  ros::spin();

  return 0;
}

