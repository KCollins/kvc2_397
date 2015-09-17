#include <ros/ros.h>
#include <stdio.h>
#include <std_msgs/Float64.h>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
		//ros::init(argc, argv, "minimal_captain");
		//ROS_INFO("Node for PS2. Prompts the user to enter a frequency and an amplitude, then sends off those values as a service request to the vel-comm node..");

	cout << "Hello world!!!!\n";  // prints Hello
	double amplitude;
  	cout << "Please enter a value for the amplitude: ";
  	cin >> amplitude;
  	cout << "The value you entered for the amplitude is " << amplitude;
  	cout << ".\n";

  	double velocity;
  	cout << "Please enter a value for the velocity: ";
  	cin >> velocity;
  	cout << "The value you entered for the velocity is " << velocity;
  	cout << ".\n";


		//ros::spin();

}