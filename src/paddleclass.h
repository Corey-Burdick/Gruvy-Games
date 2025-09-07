#include <raylib.h>

class Paddle{
public:
  float xPos;
  float yPos;
  float speed = 360;
  int width = GetScreenWidth() / 64;
  int height = GetScreenHeight() / 7;
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
