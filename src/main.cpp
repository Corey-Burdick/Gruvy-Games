#include <raylib.h>
#include <cstring>

#include "gameclass.h"

int main(int argc, char* argv[]) {
  int windowWidth = 1280;
  int windowHeight = 720;
  bool fullscreen = false;

  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] == '-') {
        for (int j = 1; j < strlen(argv[i]); j++) {
          switch (argv[i][j]) {
            case 'f':
              fullscreen = true;
              break;
            case 'h':
              windowWidth = 1920;
              windowHeight = 1080;
              break;
          }
        }
      }
    }
  }
  
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  SetConfigFlags(FLAG_MSAA_4X_HINT);
  InitWindow(windowWidth, windowHeight, "Gruvy Games");
  HideCursor();
  SetTargetFPS(240);

  if (fullscreen) {
    ToggleFullscreen();
  }

  Game game = Game();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);

    game.Update();

    game.Draw();

    EndDrawing();
  }

  if (fullscreen) {
    ToggleFullscreen();
  }
}
