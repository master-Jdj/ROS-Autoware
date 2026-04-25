// 作为控制人，PID控制算法是极其值得学习的。

#include "stdio.h"

struct _pid {
  float SetSpeed;    // 设定速度
  float ActualSpeed; // 实际速度
  float err;         // 误差
  float err_last;    // 上次误差
  float Kp, Ki, Kd;  // PID参数
  float voltage;     // 输出电压
  float integral;    // 积分
} pid;

void PID_init() {
  printf("PID_init begin\n");
  pid.SetSpeed = 0.0;
  pid.ActualSpeed = 0.0;
  pid.err = 0.0;
  pid.err_last = 0.0;
  pid.voltage = 0.0;
  pid.integral = 0.0;
  pid.Kp = 0.2;
  pid.Ki = 0.015;
  pid.Kd = 0.2;
  printf("PID_init end \n");
}

float PID_realize(float speed) {
  pid.SetSpeed = speed;
  pid.err = pid.SetSpeed - pid.ActualSpeed;
  pid.integral += pid.err;
  pid.voltage = pid.Kp * pid.err + pid.Ki * pid.integral +
                pid.Kd * (pid.err - pid.err_last);
  pid.err_last = pid.err;
  pid.ActualSpeed = pid.voltage * 1.0;
  return pid.ActualSpeed;
}

int main() {
  printf("System begin \n");
  PID_init();
  int count = 0;
  while (count < 1000) {
    float speed = PID_realize(200.0);
    printf("%f\n", speed);
    count++;
  }

  return 0;
}