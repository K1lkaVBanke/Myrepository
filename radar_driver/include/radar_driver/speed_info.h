#ifndef RADAR_DRIVER_SPEED_INFO_H
#define RADAR_DRIVER_SPEED_INFO_H

#include <ros/ros.h>
#include "std_msgs/String.h"
#include <can_msgs/Frame.h>
#include <sensor_msgs/Imu.h>
#include <radar_driver/data.h>

#include <cmath>

namespace radar_driver
{

   float time_prev;
   
   class SpeedinfoNode
   {
      public:

         SpeedinfoNode();

         void callback(const sensor_msgs::Imu & input);

         bool is_integer(float dec);

      private:

         ros::NodeHandle n_; 
         ros::Publisher pub_;
         ros::Subscriber sub_;

   };//End of class

   class YawinfoNode
   {
      public:

         YawinfoNode();

         void callback(const sensor_msgs::Imu & input);

         bool is_integer(float dec);

      private:

         ros::NodeHandle n_; 
         ros::Publisher pub_;
         ros::Subscriber sub_;

   };//End of class

};  // namespace radar_driver

#endif 
