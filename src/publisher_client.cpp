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

    // publisher stuffs
    ros::Publisher pub = nh.advertise<publisher_subscriber_server_client::Message>("add_two_ints", 1000);
    ros::Rate loop_rate(10);
    publisher_subscriber_server_client::Message msg;

    // client stufffffsss
    ros::ServiceClient client = nh.serviceClient<publisher_subscriber_server_client::Service>("add_two_ints_server");
    publisher_subscriber_server_client::Service srv;
    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);
    
    if (client.call(srv))
    {
        for(int i = 0; i < 15; i++) {
          msg.num = (long int)srv.response.sum;
          ROS_INFO("Published: %ld", msg.num);
          ROS_INFO("Sum: %ld", (long int)srv.response.sum);
          pub.publish(msg);
          loop_rate.sleep();
        }
    }
    else
    {
      ROS_ERROR("Failed to call service add_two_ints");
      return 1;
    }

    return 0;
}