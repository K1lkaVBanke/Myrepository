#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>
#include <can_msgs/Frame.h>
#include <radar_driver/data.h>
#include <radar_driver/const_vars.h>
#include <radar_driver/warning.h>

#include <iostream>
#include <cmath>

namespace radar_driver
{

   WarningNode::WarningNode()
   {
      //Topic you want to publish
      pub_ = n_.advertise<std_msgs::Int32>("/warning_messages", 10);

      //Topic you want to subscribe
      sub_ = n_.subscribe("/received_messages", 10, &WarningNode::callback, this);
   }

   void WarningNode::callback(const can_msgs::Frame & input)
   {
      std_msgs::Int32 output;
      //.... do something with the input and generate the output...

      if (input.id==1550) 
      {
         output.data = 1;

         pub_.publish(output); 
      }
   }

};  // namespace radar_driver
