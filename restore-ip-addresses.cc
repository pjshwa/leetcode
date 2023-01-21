class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    int n = s.size();
    vector<vector<string>> ans;
    vector<string> cur;

    function<void(int, int)> dfs = [&](int i, int k) {
      if (i == n && k == 4) {
        ans.push_back(cur);
        return;
      }
      if (i == n || k == 4) return;

      for (int j = i; j < i + 3 && j < n; j++) {
        string t = s.substr(i, j - i + 1);
        if (t.size() > 1 && t[0] == '0') continue;
        if (stoi(t) > 255) continue;

        cur.push_back(t);
        dfs(j + 1, k + 1);
        cur.pop_back();
      }
    };
    dfs(0, 0);

    vector<string> ret;
    for (auto &v : ans) {
      string t = "";
      for (int i = 0; i < 4; i++) {
        t += v[i];
        if (i != 3) t += '.';
      }
      ret.push_back(t);
    }
    return ret;
  }
};
