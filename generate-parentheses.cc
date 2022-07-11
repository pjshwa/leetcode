class Solution {
  vector<string> ans;
  vector<char> cur;
  int n;
  void dfs(int c, int dt) {
    if (c == n && dt == 0) {
      string res = "";
      for (char& c : cur) res += c;
      ans.push_back(res);
      return;
    }

    if (dt) {
      cur.push_back(')');
      dfs(c, dt - 1);
      cur.pop_back();
    }
    if (c < n) {
      cur.push_back('(');
      dfs(c + 1, dt + 1);
      cur.pop_back();
    }
  }
public:
  vector<string> generateParenthesis(int n) {
    this->n = n;
    dfs(0, 0);
    return ans;
  }
};
