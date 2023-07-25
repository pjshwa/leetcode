class Solution {
public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int N = arr.size();

    int l = 0, r = N;
    while (l < r) {
      int m = (l + r) / 2;

      if (m < N - 1 && arr[m] < arr[m + 1]) l = m + 1;
      else r = m;
    }
    return l;
  }
};
