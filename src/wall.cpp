#include "wall.hpp"

namespace mahjong {

/**
 * @brief Construct a wall.
 */
Wall::Wall(void) { Reset(); };

/**
 * @brief Draw a tile from the wall.
 * @return The tile drawn from the wall.
 */
Tile Wall::Draw(void) {
  Tile tile = tiles.back();
  tiles.pop_back();

  return tile;
};

/**
 * @brief Reset the wall.
 */
void Wall::Reset(void) {
  /* Clear All Tiles */
  tiles.clear();

  /* Add Tiles */
  for (int i = static_cast<int>(Tile::TypeEnum::kOneCharacter);
       i <= static_cast<int>(Tile::TypeEnum::kRedDragon); i++) {
    Tile::TypeEnum type = static_cast<Tile::TypeEnum>(i);
    for (int j = 0; j < 4; j++) {
      tiles.push_back(Tile(type));
    }
  }

  /* Shuffle Tiles */
  std::random_shuffle(tiles.begin(), tiles.end());
};

/**
 * @brief Get the number of tiles in the wall.
 * @return The number of tiles in the wall.
 */
int Wall::GetNumTiles(void) const { return tiles.size(); };

/**
 * @brief Output the wall.
 * @param os The output stream.
 * @param wall The wall.
 * @return The output stream.
 */
std::ostream& operator<<(std::ostream& os, const Wall& wall) {
  for (Tile tile : wall.tiles) {
    os << tile << " ";
  }

  return os;
};

} /* namespace mahjong */
