#ifndef GAME_CLASS_H
#define GAME_CLASS_H

#include <raylib.h>
#include "arenaclass.h"

class Game {
public:
  Arena arena = Arena();

  Game();
  void Update();
  void Draw();
};

#endif // GAME_CLASS_H 
