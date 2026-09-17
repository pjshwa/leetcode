#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minSumOfLengths(vector<int>& arr, int target) {
    int N = arr.size();
    vector<int> L(N, INT_MAX), R(N, INT_MAX);

    int sum = 0, l = 0, r = N - 1;
    for (int i = 0; i < N; ++i) {
      if (i > 0) L[i] = L[i - 1];
      sum += arr[i];
      while (sum > target) sum -= arr[l++];
      if (sum == target) L[i] = min(L[i], i - l + 1);
    }
    sum = 0;
    for (int i = N - 1; i >= 0; --i) {
      if (i < N - 1) R[i] = R[i + 1];
      sum += arr[i];
      while (sum > target) sum -= arr[r--];
      if (sum == target) R[i] = min(R[i], r - i + 1);
    }
    int ans = INT_MAX;
    for (int i = 0; i < N - 1; ++i) {
      if (L[i] < INT_MAX && R[i + 1] < INT_MAX) ans = min(ans, L[i] + R[i + 1]);
    }
    return ans == INT_MAX ? -1 : ans;
  }
};
