/**
* 该历程将订阅 /turtle1/pose话题，消息类型turtlesim::Pose
*/

#include <ros/ros.h>
#include "turtlesim/Pose.h"

//接收到订阅的信息，回进入到回调函数
void poseCallback(const turtlesim::Pose::ConstPtr& msg)   //结构长指针 指向msg
{
    //将接收到的信息打印出来
  ROS_INFO("turtle pose: x:%.0.6f, y:%0.6f)", msg->x, msg->y);
}

int main(int argc, char** argv)
{
    //初始化ROS节点
    ros::init(argc, argv, "pose_subscriber");
    //创建节点句柄
    ros::NodeHandle n;
    //创建一个订阅者对象，订阅/turtle1/pose话题，注册回调函数poseCallback
    ros::Subscriber pose_sub = n.subscribe("/turtle1/pose", 10, poseCallback);

    // 设置缓冲区大小为10，当缓冲区满时，会丢弃最旧的数据

    //循环等待回调函数
    ros::spin();

    //由于上面是死循环，所以这里其实是不会执行到的
    return 0;
}
