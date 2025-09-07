#ifndef BALL_CLASS_H
#define BALL_CLASS_H

#include <raylib.h>

class Ball{
public:
  float ballRadius;
  float xPos;
  float yPos;
  float speedX;
  float speedY;
  int width;
  int height;

  Ball();
  void Update();
  void Draw();
  void Reset();

};

#endif // BALL_CLASS_H
