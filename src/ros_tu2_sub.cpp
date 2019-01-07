#include <ros/ros.h>
#include <math.h>
#include <cstdlib>
#include"ros_tu2/tu2_msg.h"
using namespace std;

//template<typename T>
//std::vector<u_int16_t>::iterator i;
ostream& operator<< (ostream& out,const vector<u_int16_t>& v){
    out <<"{";
    size_t last = v.size()-1;
    for(size_t i = 0; i<v.size(); ++i)
    {
        out<<pow(v[i],2);
        if(i !=last)
        out<<", ";
    }
    out<<"}";
    return out;
}

void subCallback(const ros_tu2::tu2_msgConstPtr& msg){
    ROS_INFO("receive msg = %d",msg->stamp.sec);
    ROS_INFO("receive msg = %d",msg->r);
    ROS_INFO_STREAM("receive msg vector"<< msg->v);// cout 
}

int main(int argc, char*argv[])
{
    ros::init(argc,argv, "ros_tu2_sub");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<ros_tu2::tu2_msg>("hyewon",1000,subCallback);
    ros::spin();
}