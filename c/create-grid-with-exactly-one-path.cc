class Solution {
public:
  vector<string> createGrid(int m, int n) {
    vector<string> res;
    res.push_back(string(n, '.'));
    for (int i = 1; i < m; ++i) {
      res.emplace_back(n, '#');
      res.back()[n - 1] = '.';
    }
    return res;
  }
};
