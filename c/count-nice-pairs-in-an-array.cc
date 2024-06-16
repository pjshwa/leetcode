const int MOD = 1e9 + 7;

class Solution {
public:
  int countNicePairs(vector<int>& nums) {
    map<int, int> t; int ans = 0;
    for (int e : nums) {
      string s = to_string(e);
      reverse(s.begin(), s.end());
      int erev = stoi(s);
      ans = (ans + t[e - erev]++) % MOD;
    }
    return ans;
  }
};
