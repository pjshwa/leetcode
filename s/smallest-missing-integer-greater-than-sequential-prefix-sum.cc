class Solution {
public:
  int missingInteger(vector<int>& nums) {
    int N = nums.size(), i = 1;
    while (i < N && nums[i] == nums[i - 1] + 1) ++i;
    int sum = 0;
    for (int j = 0; j < i; ++j) sum += nums[j];

    set<int> s(nums.begin(), nums.end());
    while (s.count(sum)) ++sum;
    return sum;
  }
};
