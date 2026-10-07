class Solution {
public:
  int minAddToMakeValid(string s) {
    int mmin = INT_MAX, cur = 0;
    for (char c : s) {
      if (c == '(') ++cur;
      else if (c == ')') --cur;
      mmin = min(mmin, cur);
    }
    return cur - 2 * min(0, mmin);
  }

  vector<string> ans; int t = 0, N; string s, cur;
  void dfs(int i, int d) {
    if (i == N) {
      if (d == 0 && cur.size() == N - t) ans.push_back(cur);
      return;
    }
    char c = s[i];
    if (c == '(') {
      cur.push_back(c);
      dfs(i + 1, d + 1);
      cur.pop_back();
      dfs(i + 1, d);
    } else if (c == ')') {
      if (d > 0) {
        cur.push_back(c);
        dfs(i + 1, d - 1);
        cur.pop_back();
      }
      dfs(i + 1, d);
    } else {
      cur.push_back(c);
      dfs(i + 1, d);
      cur.pop_back();
    }
  }

  vector<string> removeInvalidParentheses(string s) {
    this->N = s.size(), this->t = minAddToMakeValid(s), this->s = s;
    ans.clear(), cur.clear();
    dfs(0, 0);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
  }
};
