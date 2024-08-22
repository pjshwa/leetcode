class Solution {
  string word, cur; int N;
  vector<string> ans;

  void dfs(int i, int t) {
    if (i == N) {
      ans.push_back(cur + (t ? to_string(t) : ""));
      return;
    }

    dfs(i + 1, t + 1);
    if (t) {
      string t_str = to_string(t);
      cur += t_str;
      cur += word[i];
      dfs(i + 1, 0);
      cur.resize(cur.size() - t_str.size() - 1);
    } else {
      cur += word[i];
      dfs(i + 1, 0);
      cur.pop_back();
    }
  }

public:
  vector<string> generateAbbreviations(string word) {
    this->word = word; N = word.size();
    dfs(0, 0);
    return ans;
  }
};
