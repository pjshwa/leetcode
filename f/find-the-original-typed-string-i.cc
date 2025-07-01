class Solution {
public:
  int possibleStringCount(string word) {
    int ans = 1, streak = 1, N = word.size();
    for (int i = 1; i < N; ++i) {
      if (word[i] == word[i - 1]) ++streak;
      else {
        ans += streak - 1;
        streak = 1;
      }
    }
    return ans + streak - 1;
  }
};
