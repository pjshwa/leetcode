class Solution {
public:
  long long maximumImportance(int n, vector<vector<int>>& roads) {
    vector<int> D(n);
    for (auto& r : roads) ++D[r[0]], ++D[r[1]];
    sort(D.begin(), D.end());

    long long ans = 0;
    for (long long i = 0; i < n; ++i) ans += (i + 1) * D[i];
    return ans;
  }
};
