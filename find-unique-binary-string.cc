class Solution {
public:
  string findDifferentBinaryString(vector<string>& nums) {
    int N = nums.size();
    auto nums_set = unordered_set<string>(nums.begin(), nums.end());

    for (int c = 0; c <= N; ++c) {
      string s = "";
      for (int j = 0; j < N; ++j) {
        s += (c >> j) & 1 ? '1' : '0';
      }
      if (!nums_set.count(s)) return s;
    }
    return "";
  }
};
