class Solution {
  int rev(int x) {
    int ans = 0;
    while (x) {
      ans = ans * 10 + x % 10;
      x /= 10;
    }
    return ans;
  }

public:
  int minMirrorPairDistance(vector<int>& nums) {
    int N = nums.size(), ans = N;
    map<int, int> t;
    for (int i = 0; i < N; ++i) {
      if (t.count(nums[i])) ans = min(ans, i - t[nums[i]]);
      t[rev(nums[i])] = i;
    }
    return ans == N ? -1 : ans;
  }
};
