#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int sortableIntegers(vector<int>& nums) {
    int N = nums.size(), ans = 0;
    vector<int> V, sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());

    for (int f = 1; f <= N; ++f) {
      if (N % f) continue;
      V.clear();

      for (int i = 0; i < N; i += f) {
        int minj = 0;
        for (int j = 1; j < f; ++j) {
          if (nums[i + j - 1] > nums[i + j]) {
            minj = j;
            break;
          }
        }
        for (int j = 0; j < f; ++j) V.push_back(nums[i + (minj + j) % f]);
      }
      if (V == sorted_nums) ans += f;
    }
    return ans;
  }
};
