#ifndef RADAR_POINTCLOUD_H_
#define RADAR_POINTCLOUD_H_

#include <ros/ros.h>

#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>

#include <pb_msgs/ContiRadar.h>
#include <pb_msgs/ContiList.h>
#include <sensor_msgs/PointCloud2.h>

#include <cmath>
#include <vector>

namespace radar_pointcloud
{

class RadarPointCloudTransformation
{
    private:
		ros::NodeHandle n_;
		ros::Publisher pub_;
		ros::Subscriber decoded_sub_;
		ros::Subscriber list_sub_;

		bool process_ongoing_;

		int number_of_objects_;

		int last_number_of_points_;
		int number_of_points_;

		std::vector <double> points_x_;
		std::vector <double> points_y_;
		std::vector <double> points_z_;

		typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

    public:
		RadarPointCloudTransformation();
	
		void list_fn (const pb_msgs::ContiList & input);

		void conversion_fn (const pb_msgs::ContiRadar & input);

}; // End of class

}; // namespace radar_pointcloud

#endif
