#include "game.hpp"

#include <chrono>

namespace mahjong {

/**
 * @brief Construct a game.
 */
Game::Game(void) : wall(), players{Player(), Player(), Player(), Player()} {
  round = Round::EAST;
  num_round = 0;
  Hand::LoadDistances();
}

void Game::Start(void) {
  /* Deal tiles */
  Deal();

  /* Start */
  int player_index = -1;
  while (wall.GetNumTiles() > 0) {
    player_index = (player_index + 1) % 4;
    /* Draw a tile */
    players[player_index].GetHand()->Add(wall.Draw());
    /* Select a tile to discard */
    std::cout << "Player " << player_index
              << " Hand: " << *players[player_index].GetHand() << std::endl;
    std::cout << "捨てる牌を選択してください (左から0, 1, ...) >>> : ";
    int remove_index;
    std::cin >> remove_index;
    players[player_index].GetHand()->Remove(remove_index);

    std::chrono::system_clock::time_point start =
        std::chrono::system_clock::now();
    players[player_index].GetHand()->Sort();
    std::chrono::system_clock::time_point end =
        std::chrono::system_clock::now();
    double time = static_cast<double>(
        std::chrono::duration_cast<std::chrono::microseconds>(end - start)
            .count() /
        1000.0);

    int syanten = players[player_index].GetHand()->GetSyanten();
    std::cout << "Player " << player_index
              << " 手牌: " << *players[player_index].GetHand()
              << " シャンテン数: " << syanten
              << " シャンテン数計算時間: " << time << " [ms]" << std::endl;
  }
}

void Game::Deal(void) {
  wall.Reset();

  for (int i = 0; i < 3; i++) {
    for (Player& player : players) {
      for (int j = 0; j < 4; j++) {
        player.GetHand()->Add(wall.Draw());
      }
    }
  }
  for (Player& player : players) {
    player.GetHand()->Add(wall.Draw());
    player.GetHand()->Sort();
  }
}

}  // namespace mahjong
