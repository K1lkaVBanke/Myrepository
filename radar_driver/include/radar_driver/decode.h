#ifndef RADAR_DRIVER_DECODE_H
#define RADAR_DRIVER_DECODE_H

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <can_msgs/Frame.h>
#include <pb_msgs/ContiRadar.h>
#include <pb_msgs/ContiList.h>
#include <radar_driver/data.h>

#include <cmath>

namespace radar_driver
{

   class ListCanMessageNode
   {
      private:

         ros::NodeHandle n_; 
         ros::Publisher pub_;
         ros::Subscriber sub_;

      public:

         ListCanMessageNode();

         void callback(const can_msgs::Frame & input);

   };//End of class

   Objects obj[100];
   Objects obj2[100];

   class DecodeCanMessageNode
   {

      private:

         ros::NodeHandle n_; 
         ros::Publisher pub_;
         ros::Subscriber sub_;

      public:

         DecodeCanMessageNode();

         void callback(const can_msgs::Frame & input);

   };//End of class 

};  // namespace radar_driver


#endif  
