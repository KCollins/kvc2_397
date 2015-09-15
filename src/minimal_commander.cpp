#include <ros/ros.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "minimal_commander");
	ROS_INFO("We did it");

	ros::spin();
}