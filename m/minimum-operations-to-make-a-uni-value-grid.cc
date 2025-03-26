class Solution {
public:
  int minOperations(vector<vector<int>>& grid, int x) {
    vector<int> A;
    for (auto& row : grid) for (int& e : row) A.push_back(e);
    sort(A.begin(), A.end());

    int N = A.size(), ans = 0;
    for (int i = 0; i < N; ++i) {
      if (i > 0 && (A[i] - A[i - 1]) % x) return -1;
      ans += abs(A[i] - A[N / 2]) / x;
    }
    return ans;
  }
};
