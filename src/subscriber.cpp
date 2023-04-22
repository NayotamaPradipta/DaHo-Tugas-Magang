#include "publisher_subscriber_server_client/subscriber.hpp"

void callback(const publisher_subscriber_server_client::Message::ConstPtr& msg)
{
  ROS_INFO("Server: Sum = %ld", msg->num);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "subscriber");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("add_two_ints", 1000, callback);

  ros::spin();

  return 0;
}
