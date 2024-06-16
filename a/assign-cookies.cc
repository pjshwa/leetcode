class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end(), greater<int>());
    sort(s.begin(), s.end(), greater<int>());

    int ans = 0;
    while (!g.empty() && !s.empty()) {
      if (g.back() <= s.back()) {
        ans++;
        g.pop_back();
      }
      s.pop_back();
    }
    return ans;
  }
};
