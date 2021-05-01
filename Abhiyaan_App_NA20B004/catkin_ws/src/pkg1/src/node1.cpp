#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "node1");
	
	ros::NodeHandle node_handle;
	
	ros::Publisher publisher = node_handle.advertise<std_msgs::String>("team_abhiyaan", 1); //publisher to the topic 'team_abhiyaan'
	
	ros::Rate rate(10 /*Hz*/);
	while(ros::ok())
	{
		std_msgs::String msg;
		msg.data = "Team Abhiyaan:"; //text the node publishes
		publisher.publish(msg); //publishes the message
		ros::spinOnce();
		rate.sleep();
	}
	
	return 0;
}
