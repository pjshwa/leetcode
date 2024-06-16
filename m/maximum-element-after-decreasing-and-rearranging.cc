class Solution {
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    arr[0] = 1; int N = arr.size();
    for (int i = 1; i < N; ++i) {
      arr[i] = min(arr[i], arr[i - 1] + 1);
    }
    return arr[N - 1];
  }
};
