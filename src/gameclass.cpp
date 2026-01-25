#include "gameclass.h"

Game::Game() {
  showFPS = false;
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
    gameStarted = true;
  }

  if (IsKeyPressed(KEY_F)) {
    if (!showFPS) {
      showFPS = true;
    } else {
      showFPS = false;
    }
  }
}

void Game::Draw() {
  arena.Draw();
  ball.Draw();
  cpu.Draw();
  player.Draw();

  if (paused && gameStarted) {
    player.xPos = GetScreenWidth() - player.width - 10;
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Color{255, 255, 255, 90});
    DrawText("PAUSED", GetScreenWidth() / 2 - MeasureText("PAUSED", GetScreenHeight() * 0.1f) / 2, GetScreenHeight() / 8, GetScreenHeight() * 0.1f, GRUVBOX_FG);
    DrawText("Press Q key to unpause", GetScreenWidth() / 2 - MeasureText("Press Q key to unpause", GetScreenHeight() * 0.04f) / 2, GetScreenHeight() / 2, GetScreenHeight() * 0.04f, GRUVBOX_FG);
  }

  if (paused && !gameStarted) {
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), GRUVBOX_BG);
    DrawText("GRUVY PONG", GetScreenWidth() / 2 - MeasureText("GRUVY PONG", GetScreenHeight() * 0.1f) / 2, GetScreenHeight() / 8, GetScreenHeight() * 0.1f, GRUVBOX_FG);
    DrawText("Press Q key to start!", GetScreenWidth() / 2 - MeasureText("Press Q key to unpause", GetScreenHeight() * 0.04f) / 2, GetScreenHeight() / 2, GetScreenHeight() * 0.04f, GRUVBOX_FG);
  }
  if (showFPS) {
    DrawFPS(0,0);
  }
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
