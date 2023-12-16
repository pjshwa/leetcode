class Solution {
public:
  string destCity(vector<vector<string>>& paths) {
    map<string, int> dt;
    for (auto& p : paths) {
      auto s = p[0], t = p[1];
      --dt[s]; ++dt[t];
    }

    for (auto& [k, v] : dt) {
      if (v == 1) return k;
    }
    return "";
  }
};
