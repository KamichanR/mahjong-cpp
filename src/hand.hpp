#ifndef MAHJONG_HAND_HPP_
#define MAHJONG_HAND_HPP_

#include <complex>
#include <fstream>
#include <unordered_map>
#include <vector>

#include "tile.hpp"
#include "wall.hpp"

namespace mahjong
{

  class Hand
  {
  public:
    static void LoadDistances(void);
    Hand(void);
    void Add(Tile tile);
    void Sort(void);
    void Reset(void);
    void Remove(int index);
    int GetSyanten(void) const;
    Tile GetTile(int index) const;
    friend std::ostream &operator<<(std::ostream &os, const Hand &hand);

  private:
    static std::unordered_map<int, std::vector<int>> u_distances, v_distances;
    std::vector<Tile> tiles;
    static int GetSingleKindHandId(std::vector<int> hand_vector, bool is_honour);
    static int GetSyantenFourSetsOnePair(
        std::vector<std::vector<int>> tile_matrix);
    std::vector<std::vector<int>> GetTileMatrix(void) const;
  };

} /* namespace mahjong */

#endif /* MAHJONG_HAND_HPP_ */
