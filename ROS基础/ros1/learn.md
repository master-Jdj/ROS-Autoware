ROS1系统--学习 

版本：Ubuntu20.04+ROS1 Noetic

linux切换root用户
{
	ros1@ros1-virtual-machine:~$ sudo passwd root
	[sudo] ros1 的密码： 
	新的 密码： 
	重新输入新的 密码： 
	passwd：已成功更新密码
	ros1@ros1-virtual-machine:~$ su root
	密码： 
	root@ros1-virtual-machine:/home/ros1#

	退出root用户 ~# exit
}
    

安装ROS1详见：[安装ros_20ubuntu.txt](安装ros_20ubuntu.txt)

[前言（ros是什么）]：ros系统核心通讯机制是节点计算图，基于此特点，让开发者可以快速的了解一个未知系统的工作机制。

1、ROS命令工具使用

常见命令：rostopic, rosservice, rosnode, rosparam, rosmsg, rossrv... 众多参数自行学习

~$:roscore *进入ros系统*

- turtlesim 为ros系统中的学习用的功能包，但我们要继续选择功能包中的节点，若需进入功能包目录 双击Tab键。

- rqt_graph [基于qt的可视化工具箱该工具包可以查看ros系统中的节点关系，即能够现实系统计算图] 开发工程中常常利用该工具*查看节点关系*

- rosnode [用来显示ros系统中的节点信息]  输入$:rosnode 命令可以打开帮助界面,如下：
	rosnode ping    	
	rosnode list	*列出系统中的所有节点*
	rosnode info （+ 节点名） *可以获得该节点的信息，如正在发布那些话题(pub topic)，正在服务那些服务service，正在订阅那些话题(subcribe topic)*,主机号、PID号...	
	rosnode machine	
	rosnode kill	
	rosnode cleanup	

- rostopic [用来查看话题信息] 输入$:rostopic 命令可以打开帮助界面,如下：
	rostopic bw	
	rostopic delay	
	rostopic echo	
	rostopic find	
	rostopic hz	
	rostopic info	
	rostopic list   *列出系统中的所有话题*	
	rostopic pub （+ 话题名 + 话题类型 + 参数）   发布话题命令  *-r 10 参数表示为发布频率10Hz循环发送数据（放在话题名前）*  、 *若要显示话题类型结构Twist，输入命令 ~$:rosmsg show 话题类型/Twist*
	rostopic type	

- rosservice [用来查看服务信息] 输入$:rosservice 命令可以打开帮助界面,如下：
    rosservice call	    *调用服务*
    rosservice find	*查找服务*
    rosservice list   *列出系统中的所有服务*
    rosservice info （+ 服务名）    *获得服务信息*  
    rosservice type     *获得服务类型*  
    rosservice uri  *获得服务uri*   

- rosbag [记录当前系统中的话题数据并保存] 利用场景：无人机调试。。
    使用方式：[记录数据] rosbag record -a -O 文件名  
             [（查看）复现数据] rosbag play 文件名.bag  
其中-a表示记录所有话题数据，-O表示保存为压缩包的文件名。

    
2、创建工作空间与功能包

*工作空间(workspace) 是一个存放工程开发相关文件的文件夹，结构如下：
	· src :代码空间
	· build :编译空间
	· devel :开发空间
	· install : 安装空间

*创建工作空间

·进入根目录并创建工作空间目录
		/ros1/catkin_ws/src

·初始化工作空间   会产生一个CMakeLists.txt文件，命令如下：
	{
		catkin_ws/src# catkin_init_workspace
		Creating symlink "/home/ros1/catkin_ws/src/CMakeLists.txt" pointing to "/opt/ros/noetic/share/catkin/cmake/toplevel.cmake"
	}
    

*编译工作空间及功能包创建

·对ros空间进行编译  需要退到根目录下执行/ros1/catkin_ws/ , 命令如下：
	{
		~#:pwd      // 查看当前目录
		~#:catkin_make   //编译工作空间 但编译不完全
		~#:catkin_make install   //生成的install 目录下用来存放编译后的文件
	}
	build：开发过程中的二进制文件，基本不可直接使用
	devel：开发过程中生成的可执行文件，与install类似
	src：存放源代码

·开发--创建功能包
[功能包是ros里源码的最小单元，所有源码必须放到功能包中]
创建功能包命令：在src目录下执行
*~#:catkin_create_pkg 包名 依赖包1 依赖包2 ..*
	常见依赖包：roscpp ，rospy，std_msgs
	{
		catkin_ws/src# catkin_create_pkg test_pkg roscpp rospy std_msgs   //功能包创建命令

		 ~# catkin_make    //功能包创建后再次编译工作空间,根目录
	}	
		Created file test_pkg/package.xml
		Created file test_pkg/CMakeLists.txt
		Created folder test_pkg/include/test_pkg
		Created folder test_pkg/src
		Successfully created files in /home/ros1/catkin_ws/src/test_pkg. Please adjust the values in package.xml.
		  -会在生成的test_pkg目录下生成package.xml和CMakeLists.txt文件，功能包必备文件
		  -src文件夹，存放功能包中的源代码
		  -include文件夹，存放功能包中的头文件
	

*设置环境变量  使用功能包的前置操作
根目录下添加命令：
	{
		/catkin_ws# source devel/setup.bash
	}
之后系统才能在环境里找到功能包

*检查环境变量
	{
		/catkin_ws# echo $ROS_PACKAGE_PATH
				/home/ros1/catkin_ws/src:/opt/ros/noetic/share

	}

3发布者publisher的编程实现

ROS(Master)<——>发布者publisher——>Topic——订阅者subscriber<——ROS(Slave)

{
	$:catkin_create_pkg  learning_topic (添加功能库)    //创建功能包learning_topic   
	实现代码参考 [ velocity_publisher.cpp ]


}


4订阅者subscriber的编程实现
*使用.py文件时，确保py文件的属性设置为可执行文件*

在编译.cpp文件前，需要在CMakeLists.txt中添加两个编译规则，参考[[text](CMakeList.txt)]
参考[[text](pose_subscriber.cpp)]
订阅者实现步骤：
		·初始化Ros节点
		·订阅需要的话题
		·循环等待话题消息，接收到消息后进入回调函数
		·在回调函数中完成消息的处理

其余执行命令：本次实验检测海龟位置pose
{
	$ cd ~/catkin_ws
	$ catkin_make
	$ source devel/setup.bash
	$ roscore
	$ rosrun turtlesim turtlesim_node
	$ rosrun learning_topic pose_subscriber

另外使用命令使海龟移动，参考命令: $ rosrun turtlesim turtle_teleop_key
}