#include "ballclass.h"

Ball::Ball() {
  xPos = GetScreenWidth() / 2;
  yPos = GetScreenHeight() / 2;
  ballRadius = GetScreenHeight() / 40;
  speedX = GetScreenWidth() / 3;
  speedY = GetScreenHeight() / 2;
  srand(time(NULL));
}

void Ball::Update() {
  width = GetScreenWidth();
  height = GetScreenHeight();

  xPos += speedX * GetFrameTime();
  yPos += speedY * GetFrameTime();

  if (xPos + ballRadius >= width) {
    speedX *= -1;
    Reset(false);
  } 
  if (xPos - ballRadius <= 0) {
    speedX *= -1;
    Reset(true);
  }
  if (yPos - ballRadius <= 0) {
    speedY *= -1;
    yPos = 5 + ballRadius; 
  }
  if (yPos + ballRadius >= height) {
    speedY *= -1;
    yPos = height - 5 - ballRadius;
  }
}

void Ball::Draw() {
  DrawCircle(xPos, yPos, ballRadius, BLACK);
  DrawRing(Vector2{xPos, yPos}, ballRadius * 0.5, ballRadius * 0.75, 0, 360, 20, WHITE);
  DrawText(TextFormat("%i", leftScore), GetScreenWidth() / 4, GetScreenHeight() / 8, 40, RED);
  DrawText(TextFormat("%i", rightScore), GetScreenWidth() / 4 + GetScreenWidth() / 2, GetScreenHeight() / 8, 40, BLUE);
}

void Ball::Reset(bool playerScore) {
  xPos = GetScreenWidth() / 2;
  yPos = height * 0.25 + rand() % height / 2 + 1;

  if (playerScore) {
    rightScore += 1;
  }
  if (!playerScore) {
    leftScore += 1;
  }
  
}
