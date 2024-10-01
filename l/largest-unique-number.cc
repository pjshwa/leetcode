class Solution {
public:
  int largestUniqueNumber(vector<int>& nums) {
    map<int, int> tal;
    for (int e : nums) ++tal[e];

    sort(nums.begin(), nums.end()); int N = nums.size();
    for (int i = N - 1; i >= 0; --i) {
      if (tal[nums[i]] == 1) return nums[i];
    }
    return -1;
  }
};
