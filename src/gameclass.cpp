#include "gameclass.h"

Game::Game() {

}

void Game::Update() {
  arena.Update();
  ball.Update();
}

void Game::Draw() {
  arena.Draw();
  ball.Draw();
}
