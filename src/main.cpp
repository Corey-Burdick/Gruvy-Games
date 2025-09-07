#include <raylib.h>

#include "gameclass.h"

int main() {
  int windowWidth = 1280;
  int windowHeight = 720;
  
  InitWindow(windowWidth, windowHeight, "Gruvy Games");
  ToggleFullscreen();

  Game game = Game();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);

    game.Update();

    game.Draw();

    EndDrawing();
  }
  ToggleFullscreen();
}
