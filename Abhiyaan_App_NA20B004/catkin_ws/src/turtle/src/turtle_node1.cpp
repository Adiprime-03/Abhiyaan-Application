#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Twist.h>
#include <sstream>

turtlesim::Pose t1, t2; //global variables so that scope is there for the functions

ros::Publisher velocity_publisher; //globally declared so that scope is there

void pose_callback1(const turtlesim::Pose& msgIn)
{
	t1 = msgIn;
}

void pose_callback2(const turtlesim::Pose& msgIn)
{
	t2 = msgIn;
	geometry_msgs::Twist vel_msg; //for publishing linear and angular speed

	if(t1.x-t2.x>2 && (t1.y-t2.y<1)) //before sensing the obstacle
	{
	
		vel_msg.linear.x = 2;
		vel_msg.linear.y = 0;
		vel_msg.linear.z = 0;
		vel_msg.angular.x = 0;
		vel_msg.angular.y = 0;
		vel_msg.angular.z = 0;
	}
	
	else if(t1.x>t2.x && (t1.y-t2.y<1)) //after sensing the obstacle but before overtaking it
	{
		if(t2.y<=t1.y+0.5) //deviating 
		{
			vel_msg.linear.x = 1;
			vel_msg.linear.y = 0;
			vel_msg.linear.z = 0;
			vel_msg.angular.x = 0;
			vel_msg.angular.y = 0;
			vel_msg.angular.z = 1;
		}
		else //recorrecting
		{
			vel_msg.linear.x = 1;
			vel_msg.linear.y = 0;
			vel_msg.linear.z = 0;
			vel_msg.angular.x = 0;
			vel_msg.angular.y = 0;
			vel_msg.angular.z = -0.873;
		}
	}
	else //after overtake
	{
		vel_msg.linear.x = 2;
		vel_msg.linear.y = 0;
		vel_msg.linear.z = 0;
		vel_msg.angular.x = 0;
		vel_msg.angular.y = 0;
		vel_msg.angular.z = 0;
	}
	
	velocity_publisher.publish(vel_msg); //publishes the message 
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "turtle_node1");
	ros::NodeHandle node;
	ros::NodeHandle n;
	velocity_publisher = n.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 1000); //publisher which publishes to '/turtle2/cmd_vel' to move turtle2 around
	ros::Subscriber sub1 = node.subscribe("/turtle1/pose", 1000, &pose_callback1); //subscriber to '/turtle1/pose' to get position of turtle1
	ros::Subscriber sub2 = node.subscribe("/turtle2/pose", 1000, &pose_callback2); //subscriber to '/turtle2/pose' to get position of turtle2
	ros::spin();
	
	return 0;
}
