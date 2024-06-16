class Solution {
public:
  int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {

    int ans = 0, cur = 0;
    vector<int> have(26);
    for (char c : letters) ++have[c - 'a'];

    function<void(int)> dfs = [&](int i) {
      if (i == words.size()) {
        ans = max(ans, cur);
        return;
      }
      dfs(i + 1);

      int ok = 1; vector<int> need(26);
      for (char c : words[i]) ++need[c - 'a'];
      for (int i = 0; i < 26; ++i) ok &= need[i] <= have[i];
      if (ok) {
        for (int i = 0; i < 26; ++i) {
          have[i] -= need[i];
          cur += score[i] * need[i];
        }
        dfs(i + 1);
        for (int i = 0; i < 26; ++i) {
          have[i] += need[i];
          cur -= score[i] * need[i];
        }
      }
    };

    dfs(0);
    return ans;
  }
};
