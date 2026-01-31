#include <raylib.h>
#include <cstring>

#include "gameclass.h"

int main(int argc, char* argv[]) {
  bool fullscreen = false;

  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] == '-') {
        for (int j = 1; j < strlen(argv[i]); j++) {
          switch (argv[i][j]) {
            case 'f':
              fullscreen = true;
              break;
          }
        }
      }
    }
  }
  
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  SetConfigFlags(FLAG_MSAA_4X_HINT);
  InitWindow(1920, 1080, "Gruvy Games");
  HideCursor();
  SetTargetFPS(60);

  if (fullscreen) {
    SetWindowSize(GetMonitorWidth(0), GetMonitorHeight(0));
    ToggleFullscreen();
  }

  Game game;

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
