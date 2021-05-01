#include <ros/ros.h>
#include <std_msgs/String.h>

void cb(const std_msgs::StringConstPtr& msg)
{
	std::cout << msg->data; //prints text node1 publishes
	std::cout << " ";
}

void callback(const std_msgs::StringConstPtr& msg)
{
	std::cout << msg->data << std::endl; //prints text node2 publishes
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "node3");
	
	ros::NodeHandle node_handle;
	
	ros::Subscriber subscriber1 = node_handle.subscribe("team_abhiyaan", 1, &cb); //subscribes to the topic 'team_abhiyaan' to which node1 publishes
	
	ros::Subscriber subscriber2 = node_handle.subscribe("autonomy", 1, &callback); //subscribes to the topic 'autonomy' to which node2 publishes
	
	ros::spin(); //loops and exits when user wishes
	
	return 0;
}
