#include "hand.hpp"

namespace mahjong
{

  std::unordered_map<int, std::vector<int>> Hand::u_distances, Hand::v_distances;

  /**
   * @brief Load the distances.
   * @details The distances are stored in the file "data/distances.dat". @n
   * The distances are used to calculate the syanten of the hand.
   */
  void Hand::LoadDistances(void)
  {
    std::string line;
    std::ifstream ifs;
    int id, u0, u1, u2, u3, u4, v0, v1, v2, v3, v4;

    ifs = std::ifstream("data/distances.dat");
    int count = 0;
    while (std::getline(ifs, line))
    {
      count++;
      std::istringstream iss(line);
      iss >> id >> u0 >> u1 >> u2 >> u3 >> u4 >> v0 >> v1 >> v2 >> v3 >> v4;
      Hand::u_distances[id] = {u0, u1, u2, u3, u4};
      Hand::v_distances[id] = {v0, v1, v2, v3, v4};
    }
  }

  /**
   * @brief Construct a hand.
   */
  Hand::Hand(void) { Reset(); };

  /**
   * @brief Add a tile to the hand.
   * @param tile The tile drawn from the wall.
   */
  void Hand::Add(Tile tile) { tiles.push_back(tile); };

  /**
   * @brief Sort the hand.
   */
  void Hand::Sort(void) { std::sort(tiles.begin(), tiles.end()); };

  /**
   * @brief Remove a tile from the hand.
   * @param index The index of the tile to remove.
   */
  void Hand::Remove(int index) { tiles.erase(tiles.begin() + index); };

  /**
   * @brief Reset the hand.
   */
  void Hand::Reset(void) { tiles.clear(); };

  /**
   * @brief Get the syanten of the hand.
   * @return The syanten of the hand.
   */
  int Hand::GetSyanten(void) const
  {
    std::vector<std::vector<int>> tile_matrix = GetTileMatrix();
    int syanten = GetSyantenFourSetsOnePair(tile_matrix);

    return syanten;
  };

  /**
   * @brief Get the tile.
   * @param index The index of the tile.
   * @return The tile.
   */
  Tile Hand::GetTile(int index) const
  {
    return tiles[index];
  }

  /**
   * @brief Output the hand.
   * @param os The output stream.
   * @param hand The hand.
   * @return The output stream.
   */
  std::ostream &operator<<(std::ostream &os, const Hand &hand)
  {
    for (Tile tile : hand.tiles)
    {
      os << tile << " ";
    }

    return os;
  };

  /**
   * @brief Get the matrix of the hand.
   * @details The matrix of the hand is a 4x9 matrix. @n
   * The first row is the character tiles. @n
   * The second row is the circle tiles. @n
   * The third row is the bamboo tiles. @n
   * The fourth row is the honour tiles. @n
   * @return The matrix of the hand.
   */
  std::vector<std::vector<int>> Hand::GetTileMatrix(void) const
  {
    std::vector<std::vector<int>> tile_matrix(4, std::vector<int>(9, 0));

    for (Tile tile : tiles)
    {
      if (!tile.IsStandard())
      {
        continue;
      }

      int i = static_cast<int>(tile.GetType()) / 9;
      int j = static_cast<int>(tile.GetType()) % 9;
      tile_matrix[i][j]++;
    }

    return tile_matrix;
  };

  /**
   * @brief Get the ID of the hand with a single kind.
   * @param hand_vector The vector of the hand with a single kind.
   * @param is_honour True if the hand is an honour hand, false otherwise.
   * @return The ID of the hand with a single kind.
   */
  int Hand::GetSingleKindHandId(std::vector<int> hand_vector, bool is_honour)
  {
    int id = 0;
    for (int i = 0; i < hand_vector.size(); i++)
    {
      id += hand_vector[i] * std::pow(5, i);
    }

    if (is_honour)
    {
      id += std::pow(5, hand_vector.size());
    }

    return id;
  };

  /**
   * @brief Get the syanten of the hand with four sets and one pair.
   * @param tile_matrix The matrix of the hand.
   * @return The syanten of the hand with four sets and one pair.
   */
  int Hand::GetSyantenFourSetsOnePair(std::vector<std::vector<int>> tile_matrix)
  {
    const int infinity = std::numeric_limits<int>::max();
    std::vector<std::vector<int>> u_matrix(4, std::vector<int>(5, infinity)),
        v_matrix(4, std::vector<int>(5, infinity));

    /* Calculate U, V matrix (Character) */
    int single_kind_hand_id = GetSingleKindHandId(tile_matrix[0], false);
    for (int i = 0; i < 5; i++)
    {
      u_matrix[0][i] = u_distances[single_kind_hand_id][i];
      v_matrix[0][i] = v_distances[single_kind_hand_id][i];
    }

    /* Calculate U, V matrix (Circle, Bamboo) */
    for (int k = 1; k < 3; k++)
    {
      single_kind_hand_id = GetSingleKindHandId(tile_matrix[k], false);
      for (int m = 0; m < 5; m++)
      {
        u_matrix[k][m] = infinity;
        v_matrix[k][m] = infinity;
        for (int l = 0; l <= m; l++)
        {
          u_matrix[k][m] = std::min(
              u_matrix[k][m],
              u_matrix[k - 1][l] + u_distances[single_kind_hand_id][m - l]);
          v_matrix[k][m] = std::min(
              v_matrix[k][m],
              v_matrix[k - 1][l] + v_distances[single_kind_hand_id][m - l]);
          v_matrix[k][m] = std::min(
              v_matrix[k][m],
              v_matrix[k - 1][l] + u_distances[single_kind_hand_id][m - l]);
        }
      }
    }

    /* Calculate U, V matrix (Honour) */
    single_kind_hand_id = GetSingleKindHandId(tile_matrix[3], true);
    int num_replace = infinity;
    for (int l = 0; l < 5; l++)
    {
      num_replace = std::min(
          num_replace, u_matrix[2][l] + u_distances[single_kind_hand_id][4 - l]);
      num_replace = std::min(
          num_replace, v_matrix[2][l] + v_distances[single_kind_hand_id][4 - l]);
    }

    return num_replace - 1;
  };

} // namespace mahjong
