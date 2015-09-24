#include <ros/ros.h>
#include <stdio.h>
#include <std_msgs/Float64.h>
#include <iostream>
#include <kvc2_397/ampfreq.h>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv)
{
		ros::init(argc, argv, "minimal_captain");
		ROS_INFO("Node for PS2. Prompts the user to enter a frequency and an amplitude, then sends off those values as a service request to the vel-comm node..");
ros::NodeHandle n;
   ros::ServiceClient client = n.serviceClient<kvc2_397::ampfreq>("lookup_by_name");
    kvc2_397::ampfreq srv;
    bool handshake = false;
    while (ros::ok()) {

	cout << "Hello world!!!!\n";  // prints Hello
	  double amplitude;
  	cout << "Please enter a value for the amplitude: ";
  	cin >> amplitude;
  	cout << "The value you entered for the amplitude is " << amplitude;
  	cout << ".\n";
    return amplitude;

  	double frequency;
  	cout << "Please enter a value for the velocity: ";
  	cin >> frequency;
  	cout << "The value you entered for the velocity is " << frequency;
  	cout << ".\n";
    return frequency;
    }


		//ros::spin();

}