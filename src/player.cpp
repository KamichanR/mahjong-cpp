#include "player.hpp"

namespace mahjong {

/**
 * @brief Construct a player.
 * @param score The score of the player.
 */
Player::Player() : score(25000){};

/**
 * @brief Get the hand of the player.
 * @return The hand of the player.
 */
Hand* Player::GetHand(void) { return &hand; }

} /* namespace mahjong */
