#include "ros/ros.h"
#include "publisher_subscriber_server_client/publisher_client.hpp"
#include "std_msgs/String.h"

int main(int argc, char** argv) 
{
    ros::init(argc, argv, "publisher_client");
    ros::NodeHandle nh;

    if (argc != 3)
    {
      ROS_INFO("usage: publisher_client X Y");
      return 1;
    }

    ros::ServiceClient client = nh.serviceClient<publisher_subscriber_server_client::Service>("add_two_ints");
    publisher_subscriber_server_client::Service srv;
    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);
    
    if (client.call(srv))
    {
        ROS_INFO("Sum: %ld", (long int)srv.response.sum);
    }
    else
    {
        ROS_ERROR("Failed to call service add_two_ints");
        return 1;
    }

    return 0;
}