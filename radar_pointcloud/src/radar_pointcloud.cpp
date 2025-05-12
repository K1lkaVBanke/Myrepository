#include <ros/ros.h>

#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>

#include <pb_msgs/ContiRadar.h>
#include <pb_msgs/ContiList.h>
#include <sensor_msgs/PointCloud2.h>

#include <radar_pointcloud/radar_pointcloud.h>
#include <cmath>
#include <vector>

namespace radar_pointcloud
{

RadarPointCloudTransformation::RadarPointCloudTransformation()
{
	// Parameters

	process_ongoing_ = false;
	number_of_objects_ = 0;
	last_number_of_points_ = 0;
	number_of_points_ = 0;

	// Published topics
	pub_ = n_.advertise<sensor_msgs::PointCloud2>("/radar_pointcloud",1000);
	// Subscribed topics
	list_sub_ = n_.subscribe("/list_messages", 50, &RadarPointCloudTransformation::list_fn, this);
	decoded_sub_ = n_.subscribe("/decoded_messages", 50, &RadarPointCloudTransformation::conversion_fn, this);
}

void RadarPointCloudTransformation::list_fn (const pb_msgs::ContiList & input)
{
	if (process_ongoing_ == false)
	{
		process_ongoing_ = true;

		ROS_INFO("Counting number of radar objects");
		number_of_objects_ = input.nof_objects;
	}
}

void RadarPointCloudTransformation::conversion_fn (const pb_msgs::ContiRadar & input)
{
	if (process_ongoing_ == true)
	{

		ROS_INFO("Filling point cloud of an object");
	
		double points_division;
		double length_division;
		double length_division_dec;
		double length_division_int;
		double length_step;
		double width_division;
		double width_division_dec;
		double width_division_int;
		double width_step;

		double x;
		double y;
		double z;
	
		// Counting the number of objects included in the same point cloud
		number_of_objects_ --;

		// Division of the objects for the point cloud. It depends on the longitude distance
	
		points_division = input.longitude_dist / 100; // 50 works

		length_division = input.length / points_division;
		length_division_int = round(length_division);
		length_step = input.length / length_division_int;

		width_division = input.width / points_division;
		width_division_int = round(width_division);
		width_step = input.width / width_division_int;

		last_number_of_points_ = number_of_points_;
	
		number_of_points_ = last_number_of_points_ + (length_division_int + 1) * (width_division_int + 1);

			// Loop for filling the data of the points
			for (int i = -length_division_int / 2; i < (length_division_int / 2 + 1); i++)
			{
				for (int j = -width_division_int / 2; j < (width_division_int / 2 + 1); j++)
				{	
					x = input.longitude_dist + (tan((input.orientation_angle * M_PI) / 180)) * j * width_step;
					y = input.lateral_dist + j * width_step;
					z = i * length_step;
					//ROS_INFO ("Filling loop with points");
					points_x_.push_back (x);
					points_y_.push_back (y);
					points_z_.push_back (z);
				}
			} 

		if (number_of_objects_ == 0)
		{
			ROS_INFO("Publishing point cloud");

			PointCloud::Ptr msg (new PointCloud);
			
			msg->header.frame_id = "radar";
	  		msg->height = 1;
			msg->width = number_of_points_;
			msg->header.stamp = pcl_conversions::toPCL(input.header).stamp;

			for (int n = 0; n < number_of_points_; n++)
			{
				msg->points.push_back(pcl::PointXYZ(points_x_[n], points_y_[n], points_z_[n]));
			}

	    	pub_.publish (msg);

			points_x_.clear();
			points_y_.clear();
			points_z_.clear();

			last_number_of_points_ = 0;
			number_of_points_ = 0;
		
			process_ongoing_ = false;
		}
			
	}

}
}; // namespace radar_pointcloud
