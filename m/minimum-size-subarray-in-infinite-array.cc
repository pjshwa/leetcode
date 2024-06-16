using ll = long long;

class Solution {
public:
  int minSizeSubarray(vector<int>& nums, int target) {
    ll sum = 0, N = nums.size();
    for (int e : nums) sum += e;

    ll pre = 0;
    if (target >= 3 * sum) {
      pre = (target / sum - 2) * N;
      target = (target % sum) + 2 * sum;
    }

    vector<int> nums3 = nums;
    for (int e : nums) nums3.push_back(e);
    for (int e : nums) nums3.push_back(e);

    ll r = 0, acc = 0, ans = 3 * N + 1;
    for (int l = 0; l < 3 * N; ++l) {
      while (r < 3 * N && acc + nums3[r] <= target) acc += nums3[r++];
      if (acc == target) ans = min(ans, r - l);
      acc -= nums3[l];
    }

    if (ans == 2 * N + 1) return -1;
    else return ans + pre;
  }
};
