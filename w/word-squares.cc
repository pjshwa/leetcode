class Solution {
  int N, L;
  vector<vector<string>> ans;
  string cur[4];
  unordered_set<string> words_s;

  void dfs(int r, int c) {
    if (r == L) {
      vector<string> R;
      for (int j = 0; j < L; ++j) R.push_back(cur[j]);
      ans.push_back(R);
      return;
    }

    for (char ch = 'a'; ch <= 'z'; ++ch) {
      cur[r][c] = cur[c][r] = ch;
      if (c < L - 1) dfs(r, c + 1);
      else if (words_s.count(cur[r])) dfs(r + 1, r + 1);
      cur[r][c] = cur[c][r] = ' ';
    }
  }

public:
  vector<vector<string>> wordSquares(vector<string>& words) {
    N = words.size(), L = words[0].size();
    if (L == 1) {
      for (auto& word : words) {
        ans.push_back({word});
      }
      return ans;
    }

    for (int i = 0; i < L; ++i) cur[i] = string(L, ' ');
    this->words_s = unordered_set<string>(words.begin(), words.end());

    for (auto& word1 : words) for (auto& word2 : words) {
      if (word1[1] != word2[0]) continue;
      for (int i = 0; i < L; ++i) {
        cur[i][0] = cur[0][i] = word1[i];
        cur[i][1] = cur[1][i] = word2[i];
      }
      dfs(2, 2);
    }
    return ans;
  }
};
