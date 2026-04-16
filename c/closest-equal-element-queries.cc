class Solution {
public:
  vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    int N = nums.size(), Q = queries.size();
    vector<int> A(N, N), ans;

    map<int, int> V;
    for (int i = 0; i < 2 * N; ++i) {
      int x = nums[i % N];
      if (V.count(x)) A[i % N] = min(A[i % N], i - V[x]);
      V[x] = i;
    }

    V.clear();
    for (int i = 2 * N - 1; i >= 0; --i) {
      int x = nums[i % N];
      if (V.count(x)) A[i % N] = min(A[i % N], V[x] - i);
      V[x] = i;
    }

    for (int q : queries) ans.push_back(A[q] == N ? -1 : A[q]);
    return ans;
  }
};
