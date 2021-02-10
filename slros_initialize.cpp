#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "vehicle_control";

// For Block vehicle_control/Subscribe
SimulinkSubscriber<std_msgs::Int8, SL_Bus_vehicle_control_std_msgs_Int8> Sub_vehicle_control_14;

// For Block vehicle_control/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_vehicle_control_std_msgs_Float64> Pub_vehicle_control_30;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

