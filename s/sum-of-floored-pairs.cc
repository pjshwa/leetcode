#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   int sumOfFlooredPairs(vector<int>& nums) {
    const int MAX = 1e5;
    const int MOD = 1e9 + 7;
    unordered_map<int, int> cnts;
    vector<long long> acnts(MAX + 1, 0);
    for (int num : nums) {
      cnts[num]++;
      acnts[num]++;
    }
    for (int i = 2; i <= MAX; i++) acnts[i] += acnts[i - 1];

    long long ans = 0;
    for (auto [num, cnt] : cnts) {
      for (int f = MAX / num; f > 0; --f)
        ans = (ans + cnt * f * (acnts[min(MAX, (f + 1) * num - 1)] - acnts[f * num - 1])) % 1000000007;
    }

    return ans;
  }
};


int main() {
  Solution solution;

  int n;
  vector<int> nums;

  cin >> n;
  nums.resize(n);
  for (int i = 0; i < n; i++) cin >> nums[i];
  cout << solution.sumOfFlooredPairs(nums) << endl;
}

