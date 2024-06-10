#ifndef MAHJONG_CONFIG_HPP_
#define MAHJONG_CONFIG_HPP_

namespace mahjong {

class Config {
  /* Enum class to manage the number of players. */
  enum class NumPlayerEnum {
    TWO = 2,   /* Two players. */
    THREE = 3, /* Three players. */
    FOUR = 4,  /* Four players. */
  };

  /* Enum class to manage the number of rounds. */
  enum class NumRoundEnum {
    ONE = 1,  /* One ronud game. (East) */
    TWO = 2,  /* Half round game. (East and South) */
    FOUR = 4, /* Full round game. (East, South, West, and North) */
  };

 private:
  const NumPlayerEnum num_player_enum; /* The number of players. */
  const NumRoundEnum num_round_enum;   /* The number of rounds. */
  const int initial_points;            /* The initial points. */
  const bool is_valid_open_simples;    /* Whether "kuitan" is valid. */
};

} /* namespace mahjong */

#endif /* MAHJONG_CONFIG_HPP_ */
