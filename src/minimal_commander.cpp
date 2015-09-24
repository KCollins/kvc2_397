#include <ros/ros.h>
#include <stdio.h>
#include <std_msgs/Float64.h>
#include <kvc2_397/ampfreq.h>
#define PI 3.141592653589

bool add(kvc2_397::ampfreq::Request &amp,
			kvc2_397::ampfreq::Request &freq)

{
	return true;
}




int main(int argc, char **argv)
{
	ros::init(argc, argv, "minimal_commander");
	ROS_INFO("New node based on minimal_publisher node.");

	double amplitude, frequency;
	amplitude=10;
	frequency=10;

ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<kvc2_397::ampfreq>("lookup_by_name");
    kvc2_397::ampfreq srv;
    bool handshake = true;
    
//ros::NodeHandle n; // two lines to create a publisher object that can talk to ROS
    ros::Publisher my_publisher_object = n.advertise<std_msgs::Float64>("vel_cmd", 1);
    //"vel_cmd" is the name of the topic to which we will publish
    // the "1" argument says to use a buffer size of 1; could make larger, if expect network backups
    
    std_msgs::Float64 input_float, vel_cmd; //create a variable of type "Float64", 
    // as defined in: /opt/ros/indigo/share/std_msgs
    // any message published on a ROS topic must have a pre-defined format, 
    // so subscribers know how to interpret the serialized data transmission
   
   ros::Rate naptime(100.0); //create a ros object from the ros “Rate” class; 
   //set the sleep timer for 100Hz repetition rate (arg is in units of Hz)

    input_float.data = 0.0;
    vel_cmd.data = 0.0;
    //Based on the minimal_publisher node provided. 
    
    // do work here in infinite loop (desired for this example), but terminate if detect ROS has faulted
    while (ros::ok()) 
    {
        // this loop has no sleep timer, and thus it will consume excessive CPU time
        // expect one core to be 100% dedicated (wastefully) to this small task
        input_float.data = input_float.data + 0.001; //increment by 0.0001 each iteration
       	vel_cmd.data=amplitude*sin(2*PI*frequency*input_float.data);
        my_publisher_object.publish(vel_cmd); // publish the value--of type Float64-- 
        //to the topic "topic1"
	//the next line will cause the loop to sleep for the balance of the desired period 
        // to achieve the specified loop frequency 
	naptime.sleep(); 
    }
	ros::spin();
}