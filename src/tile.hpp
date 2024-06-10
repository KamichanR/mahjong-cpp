#ifndef MAHJONG_TILE_HPP_
#define MAHJONG_TILE_HPP_

#include <compare>
#include <iostream>
#include <string>
#include <vector>

namespace mahjong {

/**
 * @brief Tile class
 */
class Tile {
 public:
  enum class TypeEnum {
    kNone = -1,      /* None */
    kOneCharacter,   /* 1 Character */
    kTwoCharacter,   /* 2 Character */
    kThreeCharacter, /* 3 Character */
    kFourCharacter,  /* 4 Character */
    kFiveCharacter,  /* 5 Character */
    kSixCharacter,   /* 6 Character */
    kSevenCharacter, /* 7 Character */
    kEightCharacter, /* 8 Character */
    kNineCharacter,  /* 9 Character */
    kOneCircle,      /* 1 Circle */
    kTwoCircle,      /* 2 Circle */
    kThreeCircle,    /* 3 Circle */
    kFourCircle,     /* 4 Circle */
    kFiveCircle,     /* 5 Circle */
    kSixCircle,      /* 6 Circle */
    kSevenCircle,    /* 7 Circle */
    kEightCircle,    /* 8 Circle */
    kNineCircle,     /* 9 Circle */
    kOneBamboo,      /* 1 Bamboo */
    kTwoBamboo,      /* 2 Bamboo */
    kThreeBamboo,    /* 3 Bamboo */
    kFourBamboo,     /* 4 Bamboo */
    kFiveBamboo,     /* 5 Bamboo */
    kSixBamboo,      /* 6 Bamboo */
    kSevenBamboo,    /* 7 Bamboo */
    kEightBamboo,    /* 8 Bamboo */
    kNineBamboo,     /* 9 Bamboo */
    kEastWind,       /* East Wind */
    kSouthWind,      /* South Wind */
    kWestWind,       /* West Wind */
    kNorthWind,      /* North Wind */
    kWhiteDragon,    /* White Dragon */
    kGreenDragon,    /* Green Dragon */
    kRedDragon,      /* Red Dragon */
    kSpringSeason,   /* Spring Season */
    kSummerSeason,   /* Summer Season */
    kAutumnSeason,   /* Autumn Season */
    kWinterSeason,   /* Winter Season */
  };

  Tile(TypeEnum TypeEnum);
  bool IsBamboo(void) const;
  bool IsCharacter(void) const;
  bool IsCircle(void) const;
  bool IsDragon(void) const;
  bool IsHonour(void) const;
  bool IsStandard(void) const;
  bool IsSimple(void) const;
  bool IsSeason(void) const;
  bool IsSuit(void) const;
  bool IsTerminal(void) const;
  bool IsWind(void) const;
  bool operator==(const Tile& other) const;
  std::weak_ordering operator<=>(const Tile& other) const;
  friend std::ostream& operator<<(std::ostream& os, const Tile& tile);
  TypeEnum GetType(void) const;

 private:
  TypeEnum type;
};

}  // namespace mahjong

#endif  // MAHJONG_TILE_HPP_
