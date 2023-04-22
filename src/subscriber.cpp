#include "ros/ros.h"
#include "publisher_subscriber_server_client/Message.h"

void callback(const publisher_subscriber_server_client::Message::ConstPtr& msg)
{
    ROS_INFO("Received message: %ld", msg->num);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "subscriber");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("message_topic", 1000, callback);

    ros::spin();

    return 0;
}
