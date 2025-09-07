#include <raylib.h>

class Paddle{
public:
  float xPos;
  float yPos;
  float speed = 360;
  int width = 25;
  int height = 120;
  Color color;
  
  void Draw();
};

class CpuPaddle : public Paddle{
public:
  CpuPaddle();
  void Update(int ball_y);
};

class PlayerPaddle : public Paddle{
public:
  PlayerPaddle();
  void Update();
};
