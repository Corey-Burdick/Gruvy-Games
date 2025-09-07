#ifndef GAME_CLASS_H
#define GAME_CLASS_H

#include <raylib.h>
#include "arenaclass.h"
#include "ballclass.h"
#include "paddleclass.h"

class Game {
public:
  Arena arena = Arena();
  Ball ball = Ball();
  CpuPaddle cpu = CpuPaddle();
  PlayerPaddle player = PlayerPaddle();

  Game();
  void Update();
  void Draw();
};

#endif // GAME_CLASS_H 
