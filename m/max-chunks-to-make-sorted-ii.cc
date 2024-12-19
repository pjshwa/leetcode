class Solution {
public:
  int maxChunksToSorted(vector<int>& arr) {
    int N = arr.size(), ans = 1, maxl = -1;
    vector<int> P(N); P[N - 1] = arr[N - 1];
    for (int i = N - 2; i >= 0; --i) P[i] = min(P[i + 1], arr[i]);
    for (int i = 0; i < N - 1; ++i) {
      maxl = max(maxl, arr[i]);
      if (P[i + 1] >= maxl) ++ans;
    }
    return ans;
  }
};
