#include "gameclass.h"

Game::Game() {

}

void Game::Update() {
  arena.Update();
  ball.Update();
  cpu.Update(ball.yPos);
  player.Update();
}

void Game::Draw() {
  arena.Draw();
  ball.Draw();
  cpu.Draw();
  player.Draw();
}
