#include "gameclass.h"

Game::Game() {

}

void Game::Update() {
  arena.Update();
  ball.Update();
  cpu.Update(ball.yPos);
  player.Update();

  if (CheckCollisionCircleRec(Vector2{ball.xPos, ball.yPos}, ball.ballRadius, Rectangle{player.xPos, player.yPos, (float)player.width, (float)player.height})) {
    ball.speedX *= -1;
    ball.xPos -= 5;
  }

  if (CheckCollisionCircleRec(Vector2{ball.xPos, ball.yPos}, ball.ballRadius, Rectangle{cpu.xPos, cpu.yPos, (float)cpu.width, (float)cpu.height})) {
    ball.speedX *= -1;
    ball.xPos += 5;
  }
}

void Game::Draw() {
  arena.Draw();
  ball.Draw();
  cpu.Draw();
  player.Draw();
}
