#ifndef MAHJONG_WALL_HPP_
#define MAHJONG_WALL_HPP_

#include <iostream>
#include <vector>

#include "tile.hpp"

namespace mahjong {

/**
 * @brief Wall class
 */
class Wall {
 public:
  Wall(void);
  Tile Draw(void);
  void Reset(void);
  int GetNumTiles(void) const;
  friend std::ostream& operator<<(std::ostream& os, const Wall& wall);

 private:
  std::vector<Tile> tiles;
};

}  // namespace mahjong

#endif  // MAHJONG_WALL_HPP_
