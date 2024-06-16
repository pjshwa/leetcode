class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    set<int> players;
    map<int, int> losses;

    for (auto& match : matches) {
      int w = match[0], l = match[1];
      players.insert(w); players.insert(l);
      losses[l]++;
    }

    vector<int> zlos, olos;
    for (int player : players) {
      if (losses[player] == 0) zlos.push_back(player);
      if (losses[player] == 1) olos.push_back(player);
    }

    return {zlos, olos};
  }
};
