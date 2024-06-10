#ifndef MAHJONG_PLAYER_HPP_
#define MAHJONG_PLAYER_HPP_

#include "hand.hpp"
#include "tile.hpp"
#include "wall.hpp"

namespace mahjong {

class Player {
 public:
  Player(void);
  Hand* GetHand(void);

 private:
  Hand hand;
  int score;
};

} /* namespace mahjong */

#endif /* MAHJONG_PLAYER_HPP_ */
