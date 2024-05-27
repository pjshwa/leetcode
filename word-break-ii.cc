class Solution {
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    int N = s.size();
    int W[N][N]; memset(W, 0, sizeof(W));
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    for (int i = 0; i < N; ++i) for (int j = i; j < N; ++j) {
      W[i][j] = dict.count(s.substr(i, j - i + 1));
    }

    string cur; vector<string> ans;
    function<void(int)> dfs = [&](int i) {
      if (i == N) {
        ans.push_back(cur);
        return;
      }
      for (int j = i; j < N; ++j) {
        if (W[i][j]) {
          string word = s.substr(i, j - i + 1);
          if (cur.size()) cur += " ";
          cur += word;
          dfs(j + 1);
          cur.resize(cur.size() - word.size());
          if (cur.size()) cur.pop_back();
        }
      }
    };

    dfs(0);
    return ans;
  }
};
