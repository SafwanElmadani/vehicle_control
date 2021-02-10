#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block vehicle_control/Subscribe
extern SimulinkSubscriber<std_msgs::Int8, SL_Bus_vehicle_control_std_msgs_Int8> Sub_vehicle_control_14;

// For Block vehicle_control/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_vehicle_control_std_msgs_Float64> Pub_vehicle_control_30;

void slros_node_init(int argc, char** argv);

#endif
