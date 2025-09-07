#include "ballclass.h"

Ball::Ball() {
  xPos = GetScreenWidth() / 2;
  yPos = GetScreenHeight() / 2;
  ballRadius = 40;
  speedX = speedY = 400;
}

void Ball::Update() {
  width = GetScreenWidth();
  height = GetScreenHeight();

  xPos += speedX * GetFrameTime();
  yPos += speedY * GetFrameTime();

  if (xPos + ballRadius >= width) {
    speedX *= -1;
    xPos = width - 5 - ballRadius;
  } 
  if (xPos - ballRadius <= 0) {
    speedX *= -1;
    xPos = 5 + ballRadius;
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
}
