// axis.h
#ifndef AXIS_H
#define AXIS_H

#define AXIS_X 0
#define AXIS_Y 1
#define AXIS_Z 2
#define AXIS_A 3
#define AXIS_B 4
#define AXIS_C 5
#define AXIS_U 6
#define AXIS_V 7
#define AXIS_W 8
#define AXIS_COUNT 9

struct AxisConfig {
  float steps_per_mm;
  float feed_rate;
  float acceleration;
  float deceleration;
  float jerk;
  int microsteps;
  float soft_limit_low;
  float soft_limit_high;
};

extern AxisConfig axes[AXIS_COUNT];
extern const char* axis_names[AXIS_COUNT];

#endif
