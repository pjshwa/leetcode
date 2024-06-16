class Solution {
  int d[100'001];
  vector<int> nums;

  bool valid2(int i) {
    return nums[i] == nums[i - 1];
  }

  bool valid3(int i) {
    bool ret = nums[i] == nums[i - 1] && nums[i] == nums[i - 2];
    ret |= (nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2);
    return ret;
  }

public:
  bool validPartition(vector<int>& nums) {
    int n = nums.size();
    this->nums = nums;

    memset(d, 0, sizeof(d));
    d[0] = 1;

    for (int i = 1; i <= n; i++) {
      if (i >= 2) d[i] |= (d[i - 2] && valid2(i - 1));
      if (i >= 3) d[i] |= (d[i - 3] && valid3(i - 1));
    }

    return d[n];
  }
};
