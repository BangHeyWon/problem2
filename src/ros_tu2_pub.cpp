#include <ros/ros.h> 
#include <cstdlib>
#include<vector>
#include "ros_tu2/tu2_msg.h"
using namespace std;

int main(int argc, char *argv[]){
    ros::init(argc,argv, "ros_tu2_pub");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<ros_tu2::tu2_msg>("hyewon",1000);
    ros::Rate loop_rate(10);
    ros_tu2::tu2_msg msg;
    std::vector<u_int16_t>::iterator i;

    srand(time(NULL));
    u_int16_t num;
    u_int16_t num2;
    int count = 0;
    while(ros::ok())
    {
        msg.stamp = ros::Time::now();
        num = rand()%20+1;
        msg.v.assign(num,0);
        count=0;
        msg.r=num;
        i = msg.v.begin();
       while(i != msg.v.end()){
        *i = rand()%20+1;
        i++;
        }
    pub.publish(msg);
    loop_rate.sleep();
    count++;
    }    
    return 0;

}

//아무것도 하지 않음. ros_tutorials_pub.cpp에서 복붙한 내용임!