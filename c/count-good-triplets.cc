class Solution {
public:
  int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int N = arr.size(), ans = 0;
    for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) for (int k = j + 1; k < N; ++k) {
      int c1 = abs(arr[i] - arr[j]) <= a;
      int c2 = abs(arr[j] - arr[k]) <= b;
      int c3 = abs(arr[i] - arr[k]) <= c;
      ans += c1 && c2 && c3;
    }
    return ans;
  }
};
