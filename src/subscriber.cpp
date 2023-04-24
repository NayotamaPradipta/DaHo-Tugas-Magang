#include "publisher_subscriber_server_client/subscriber.hpp"

void callback(const publisher_subscriber_server_client::Message::ConstPtr& msg)
{
  ROS_INFO("%ld", msg->data);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "subscriber");
  ros::NodeHandle nh;

  ros::Subscriber topic_sub = nh.subscribe("topic", 1000, callback);
  
  ros::spin();
  
  return 0;
}
