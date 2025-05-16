const int INF = 0x3f3f3f3f;

class Solution {
  int hammingDistance(const string& a, const string& b) {
    if (a.size() != b.size()) return INF;
    int ret = 0;
    for (int i = 0; i < a.size(); ++i) ret += (a[i] != b[i]);
    return ret;
  }

public:
  vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
    int N = words.size(), t = 1;
    vector<int> dp(N, 1);
    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < i; ++j) {
        if (groups[i] == groups[j]) continue;
        if (hammingDistance(words[i], words[j]) == 1) dp[i] = max(dp[i], dp[j] + 1);
      }
      t = max(t, dp[i]);
    }

    vector<string> ret;
    string lastStr = ""; int lastGroup = -1;
    for (int i = N - 1; i >= 0; --i) {
      if (dp[i] != t) continue;
      if (lastGroup != -1 && lastGroup == groups[i]) continue;
      if (lastStr != "" && hammingDistance(lastStr, words[i]) != 1) continue;
      ret.push_back(words[i]);
      lastStr = words[i];
      lastGroup = groups[i];
      --t;
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};
