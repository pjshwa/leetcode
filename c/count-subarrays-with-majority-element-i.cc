#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countMajoritySubarrays(vector<int>& nums, int target) {
    int N = nums.size();
    vector<int> P(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
      P[i] = P[i - 1] + (nums[i - 1] == target ? 1 : 0);
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i) for (int j = i; j <= N; ++j) {
      int count = P[j] - P[i - 1];
      ans += (count > (j - i + 1) / 2);
    }
    return ans;
  }
};
