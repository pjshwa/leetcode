class Solution {
public:
  int minPatches(vector<int>& nums, int n) {
    int ans = 0; long long sum = 0;
    while (!nums.empty() && nums.back() > n) nums.pop_back();

    for (int e : nums) {
      while (e > sum + 1) {
        sum += sum + 1;
        ++ans;
      }
      sum += e;
    }
    while (sum < n) {
      sum += sum + 1;
      ++ans;
    }
    return ans;
  }
};
