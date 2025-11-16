const int MOD = 1e9 + 7;

class Solution {
public:
  int numSub(string s) {
    long long ans = 0, streak = 0;

    auto add_reset = [&]() {
      auto val = streak * (streak + 1) / 2;
      ans = (ans + val) % MOD;
      streak = 0;
    };
    for (char c : s) {
      if (c == '1') ++streak;
      else add_reset();
    }
    add_reset();
    return ans;
  }
};
