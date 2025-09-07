#include "arenaclass.h"

Arena::Arena() {
}

void Arena::Update() {
  width = GetScreenWidth();
  height = GetScreenHeight();
}

void Arena::Draw() {
  DrawRectangle(0, 0, width / 2, height, BLUE);
  DrawRectangle(width / 2, 0, width / 2, height, RED);
  DrawCircle(0, height / 2, height * 0.75 / 2, BLACK);
  DrawCircle(0, height / 2, height * 0.70 / 2, RED);
  DrawCircle(width, height / 2, height * 0.75 / 2, BLACK);
  DrawCircle(width, height / 2, height * 0.70 / 2, BLUE);
  DrawRectangle(width / 2 - 8, 0, 16, height * 0.25, BLACK);
  DrawRectangle(width / 2 - 8, height * 0.75, 16, height * 0.25, BLACK);
  DrawRing(Vector2{(float)width / 2, (float)height / 2}, height * 0.23, height * 0.25, 0, 360, 60, BLACK);
  DrawFPS(0, 0);
}
