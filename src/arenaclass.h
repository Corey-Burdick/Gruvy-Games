#ifndef ARENA_CLASS_H
#define ARENA_CLASS_H

#include <raylib.h>
#include "gruvboxcolors.h"

class Arena{
public:
  int width;
  int height;

  Arena();
  void Update();
  void Draw();
};

#endif // ARENA_CLASS_H
