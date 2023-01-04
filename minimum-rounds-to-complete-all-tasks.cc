class Solution {
public:
  int minimumRounds(vector<int>& tasks) {
    map<int, int> t;
    for (auto& v : tasks) t[v]++;

    int ans = 0;
    for (auto& [_, v] : t) {
      if (v == 1) return -1;
      ans += (v - 1) / 3 + 1;
    }
    return ans;
  }
};
