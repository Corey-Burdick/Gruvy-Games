#ifndef GAME_CLASS_H
#define GAME_CLASS_H

#include <raylib.h>
#include "arenaclass.h"
#include "ballclass.h"
#include "paddleclass.h"
#include "gruvboxcolors.h"

class Game {
public:
  Arena arena = Arena();
  Ball ball = Ball();
  CpuPaddle cpu = CpuPaddle();
  PlayerPaddle player = PlayerPaddle();
  bool paused = true;
  bool gameStarted = false;

  Game();
  void Update();
  void Draw();
private:
  void m_togglePaused();
};

#endif // GAME_CLASS_H 
