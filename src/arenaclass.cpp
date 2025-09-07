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
}
