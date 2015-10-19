// Kristina Collins, kvc2, EECS 600 Fall 2015
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
    ROS_INFO("Node for PS2. Prompts the user to enter a frequency and an amplitude, then sends off those values as a service request to the vel-comm node.");
ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<kvc2_397::ampfreq>("amp_freq");
    kvc2_397::ampfreq srv;
while (ros::ok()) {

	cout << "Hello world!!!!\n";  // prints Hello
	  double in_amp;
  	cout << "Please enter a value for the amplitude: ";
  	cin >> in_amp;
  	cout << "The value you entered for the amplitude is " << in_amp;
  	cout << ".\n";
       srv.request.amp=in_amp;

    double in_freq;
    cout << "Please enter a value for the frequency: ";
    cin >> in_freq;
    cout << "The value you entered for the frequency is " << in_freq;
    cout << ".\n";
    srv.request.freq=in_freq;
    

    if (client.call(srv)) {
      ROS_INFO("Successful call.");
    } 
    else ROS_WARN("Call not successful.");

     ros::spinOnce();
   }
   return true;
}