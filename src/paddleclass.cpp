#include "paddleclass.h"

void Paddle::Draw() {
  DrawRectangle(xPos, yPos, width, height, color);
  DrawRectangleRoundedLinesEx(Rectangle{xPos, yPos, (float)width, (float)height}, 0.4, 10, 3, GRUVBOX_FG);
} 

CpuPaddle::CpuPaddle() {
  xPos =  10;
  yPos = GetScreenHeight() / 2 - height / 2;
  color = GRUVBOX_BLUE; 
}

void CpuPaddle::Update(int ball_y) {
  width = GetScreenWidth() / 64;
  height = GetScreenHeight() / 7;
  if (yPos + height / 2 > ball_y) {
    yPos -= speed * GetFrameTime();
  }
    
  if (yPos + height / 2 <= ball_y) {
    yPos += speed * GetFrameTime();
  }

  if (yPos > GetScreenHeight() - height) {
    yPos = GetScreenHeight() - height;
  }
}

PlayerPaddle::PlayerPaddle() {
  xPos = GetScreenWidth() - width - 10;
  yPos = GetScreenHeight() / 2 - height / 2;
  color = GRUVBOX_RED;
}

void PlayerPaddle::Update() {
  width = GetScreenWidth() / 64;
  height = GetScreenHeight() / 7;
  xPos = GetScreenWidth() - width - 10;
  if (IsKeyDown(KEY_UP)) {
    yPos -= speed * GetFrameTime();
  } else if (IsKeyDown(KEY_DOWN)) {
    yPos += speed * GetFrameTime();
  }

  if (yPos < 0) {
    yPos = 0;
  }

  if (yPos > GetScreenHeight() - height) {
    yPos = GetScreenHeight() - height;
  }
}
