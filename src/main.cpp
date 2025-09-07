#include <raylib.h>

#include "gameclass.h"

int main() {
  Game game = Game();   
  int windowWidth = 1280;
  int windowHeight = 720;
  
  InitWindow(windowWidth, windowHeight, "Gruvy Games");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);

    game.Update();

    game.Draw();

    EndDrawing();
  }
}
