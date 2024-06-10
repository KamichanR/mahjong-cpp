#include "tile.hpp"

namespace mahjong {

/**
 * @brief Construct a tile.
 * @param typeE The type of the tile.
 */
Tile::Tile(TypeEnum type) : type(type) {}

/**
 * @brief Determine if the tile is a bamboo tile.
 * @return True if the tile is a bamboo tile, false otherwise.
 */
bool Tile::IsBamboo(void) const {
  return TypeEnum::kOneBamboo <= type && type <= TypeEnum::kNineBamboo;
}

/**
 * @brief Determine if the tile is a character tile.
 * @return True if the tile is a character tile, false otherwise.
 */
bool Tile::IsCharacter(void) const {
  return TypeEnum::kOneCharacter <= type && type <= TypeEnum::kNineCharacter;
}

/**
 * @brief Determine if the tile is a circle tile.
 * @return True if the tile is a circle tile, false otherwise.
 */
bool Tile::IsCircle(void) const {
  return TypeEnum::kOneCircle <= type && type <= TypeEnum::kNineCircle;
}

/**
 * @brief Determine if the tile is a dragon tile.
 * @return True if the tile is a dragon tile, false otherwise.
 */
bool Tile::IsDragon(void) const {
  return TypeEnum::kWhiteDragon <= type && type <= TypeEnum::kRedDragon;
}

/**
 * @brief Determine if the tile is a honour tile.
 * @return True if the tile is a honour tile, false otherwise.
 */
bool Tile::IsHonour(void) const { return IsWind() || IsDragon(); }

/**
 * @brief Determine if the tile is a simple tile.
 * @return True if the tile is a simple tile, false otherwise.
 */
bool Tile::IsSimple(void) const { return IsSuit() && !IsTerminal(); }

/**
 * @brief Determine if the tile is a season tile.
 * @return True if the tile is a season tile, false otherwise.
 */
bool Tile::IsSeason(void) const {
  return TypeEnum::kSpringSeason <= type && type <= TypeEnum::kWinterSeason;
}

/**
 * @brief Determine if the tile is a standard tile (suit or honour).
 * @return True if the tile is a standard tile, false otherwise.
 */
bool Tile::IsStandard(void) const { return IsSuit() || IsHonour(); }

/**
 * @brief Determine if the tile is a suit tile.
 * @return True if the tile is a suit tile, false otherwise.
 */
bool Tile::IsSuit(void) const {
  return TypeEnum::kOneCharacter <= type && type <= TypeEnum::kNineBamboo;
}

/**
 * @brief Determine if the tile is a terminal tile.
 * @return True if the tile is a terminal tile, false otherwise.
 */
bool Tile::IsTerminal(void) const {
  return type == TypeEnum::kOneCharacter || type == TypeEnum::kNineCharacter ||
         type == TypeEnum::kOneCircle || type == TypeEnum::kNineCircle ||
         type == TypeEnum::kOneBamboo || type == TypeEnum::kNineBamboo;
}

/**
 * @brief Determine if the tile is a wind tile.
 * @return True if the tile is a wind tile, false otherwise.
 */
bool Tile::IsWind(void) const {
  return TypeEnum::kEastWind <= type && type <= TypeEnum::kNorthWind;
}

/**
 * @brief Compare two tiles.
 * @param other The other tile.
 * @return True if the two tiles are the same, false otherwise.
 */
bool Tile::operator==(const Tile& other) const { return type == other.type; }

/**
 * @brief Compare two tiles.
 * @param other The other tile.
 * @return 1 if this tile is greater than the other tile,
 *  0 if they are the same, -1 if this tile is less than the other tile.
 */
std::weak_ordering Tile::operator<=>(const Tile& other) const {
  return type <=> other.type;
}

/**
 * @brief Output the tile to the output stream.
 * @param os The output stream.
 * @param tile The tile.
 * @return The output stream.
 */
std::ostream& operator<<(std::ostream& os, const Tile& tile) {
  if (tile.IsBamboo()) {
    os << static_cast<int>(tile.type) % 9 + 1 << "索";
  } else if (tile.IsCharacter()) {
    os << static_cast<int>(tile.type) % 9 + 1 << "萬";
  } else if (tile.IsCircle()) {
    os << static_cast<int>(tile.type) % 9 + 1 << "筒";
    // } else if (tile.IsHonour()) {
    //   os << static_cast<int>(tile.type) % 9 + 1 << "";
  } else if (tile.IsSeason()) {
    os << static_cast<int>(tile.type) % 34 + 1 << "b";
  } else {
    switch (static_cast<int>(tile.type) % 9 + 1) {
      case 1:
        os << "東";
        break;
      case 2:
        os << "南";
        break;
      case 3:
        os << "西";
        break;
      case 4:
        os << "北";
        break;
      case 5:
        os << "白";
        break;
      case 6:
        os << "發";
        break;
      case 7:
        os << "中";
        break;
      default:
        os << "Unknown";
        break;
    }
  }

  return os;
}

/**
 * @brief Get the type of the tile.
 * @return The type of the tile.
 */
Tile::TypeEnum Tile::GetType(void) const { return type; }

}  // namespace mahjong
