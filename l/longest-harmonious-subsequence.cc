class Solution {
public:
  int findLHS(vector<int>& nums) {
    map<int, int> t;
    for (int e : nums) ++t[e];

    auto get = [&](int k) {
      auto it = t.find(k);
      return it == t.end() ? 0 : it->second;
    };

    int ans = 0;
    for (auto& [k, v1] : t) {
      int v2 = get(k + 1);
      if (v2 > 0) ans = max(ans, v1 + v2);
    }
    return ans;
  }
};
