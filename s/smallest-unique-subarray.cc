using ll = long long;

const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9, BASE = 1e5 + 7;

class Solution {
  bool check(vector<int>& nums, int len) {
    unordered_map<ll, int> C;
    ll hash1 = 0, hash2 = 0, base1 = 1, base2 = 1;
    for (int i = 0; i < len; ++i) {
      hash1 = (hash1 * BASE + nums[i]) % MOD1;
      hash2 = (hash2 * BASE + nums[i]) % MOD2;
      if (i < len - 1) {
        base1 = (base1 * BASE) % MOD1;
        base2 = (base2 * BASE) % MOD2;
      }
    }
    ++C[hash1 * MOD2 + hash2];
    for (int i = len; i < nums.size(); ++i) {
      hash1 = ((hash1 - nums[i - len] * base1 % MOD1 + MOD1) * BASE + nums[i]) % MOD1;
      hash2 = ((hash2 - nums[i - len] * base2 % MOD2 + MOD2) * BASE + nums[i]) % MOD2;
      ++C[hash1 * MOD2 + hash2];
    }
    for (auto& [_, c] : C) {
      if (c == 1) return true;
    }
    return false;
  }

public:
  int smallestUniqueSubarray(vector<int>& nums) {
    int l = 0, r = nums.size();
    while (l < r) {
      int m = (l + r) / 2;
      if (check(nums, m)) r = m;
      else l = m + 1;
    }
    return l;
  }
};
