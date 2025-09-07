#include "gameclass.h"

Game::Game() {

}

void Game::Update() {
  arena.Update();
}

void Game::Draw() {
  arena.Draw();
}
