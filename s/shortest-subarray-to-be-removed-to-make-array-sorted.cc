class Solution {
public:
  int findLengthOfShortestSubarray(vector<int>& arr) {
    int N = arr.size(); int r = N - 1;
    while (r > 0 && arr[r - 1] <= arr[r]) --r;

    int ans = r;
    for (int l = 0; l < N; ++l) {
      if (l > 0 && arr[l - 1] > arr[l]) break;
      while (r < N && arr[r] < arr[l]) ++r;
      ans = min(ans, max(0, r - l - 1));
    }
    return ans;
  }
};
