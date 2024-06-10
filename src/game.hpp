#ifndef MAHJONG_GAME_HPP_
#define MAHJONG_GAME_HPP_

#include <string>

#include "player.hpp"
#include "wall.hpp"

namespace mahjong {

class Game {
  enum class Round {
    EAST,
    SOUTH,
    WEST,
    NORTH,
  };

 public:
  Game(void);
  void Start(void);

 private:
  Wall wall;
  Player players[4];
  void Deal(void);
  Round round;
  int num_round;
};

}  // namespace mahjong

#endif /* MAHJONG_GAME_HPP_ */
