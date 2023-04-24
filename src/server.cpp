#include "publisher_subscriber_server_client/server.hpp"

bool add(publisher_subscriber_server_client::Service::Request  &req,
             publisher_subscriber_server_client::Service::Response &res)
{
    res.sum = req.A + req.B;
    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "server");
    ros::NodeHandle nh;

    ros::ServiceServer service = nh.advertiseService("penjumlahan", add);
    ROS_INFO("Ready to add two ints.");
    ros::spin();
    return 0;
}