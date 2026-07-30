class Solution {
public:
  int minimumPushes(string word) {
    int ans = 0, cnt = 0;
    for (int j = 0; j < word.size(); ++j) {
      if (j % 8 == 0) ++cnt;
      ans += cnt;
    }
    return ans;
  }
};
