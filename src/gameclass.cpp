#include "gameclass.h"

Game::Game() {

}

void Game::Update() {
  arena.Update();
  if (!paused) {
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

  if (IsKeyPressed(KEY_Q)) {
    m_togglePaused();
  }
}

void Game::Draw() {
  arena.Draw();
  ball.Draw();
  cpu.Draw();
  player.Draw();
}

void Game::m_togglePaused() {
  switch (paused) {
    case true:
      paused = false;
      break;
    case false:
      paused = true;
      break;
  }
}
