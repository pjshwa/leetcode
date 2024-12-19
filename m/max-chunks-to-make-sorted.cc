class Solution {
public:
  int maxChunksToSorted(vector<int>& arr) {
    int N = arr.size(), ans = 0, maxl = -1;
    for (int i = 0; i < N; ++i) {
      maxl = max(maxl, arr[i]);
      if (i == maxl) ++ans;
    }
    return ans;
  }
};
