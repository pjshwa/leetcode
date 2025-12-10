const int MOD = 1e9 + 7;

class Solution {
public:
  int countPermutations(vector<int>& complexity) {
    int N = complexity.size(), ans = 1;
    for (int i = 1; i < N; ++i) {
      if (complexity[i] <= complexity[0]) return 0;
      ans = (ans * (long long)i) % MOD;
    }
    return ans;
  }
};
