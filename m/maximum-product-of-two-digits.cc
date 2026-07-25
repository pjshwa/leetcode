class Solution {
public:
  int maxProduct(int n) {
    vector<int> ds;
    while (n) {
      ds.push_back(n % 10);
      n /= 10;
    }
    int Z = ds.size(), ans = 0;
    for (int i = 0; i < Z; ++i) for (int j = i + 1; j < Z; ++j) {
      ans = max(ans, ds[i] * ds[j]);
    }
    return ans;
  }
};
