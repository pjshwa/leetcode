class Solution {
public:
  int minMoves(vector<vector<int>>& rooks) {
    vector<int> v1, v2;
    for (auto& v : rooks) {
      v1.push_back(v[0]);
      v2.push_back(v[1]);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int ans = 0, N = v1.size();
    for (int i = 0; i < N; ++i) ans += abs(v1[i] - i) + abs(v2[i] - i);
    return ans
  }
};
