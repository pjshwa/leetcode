class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    auto nsort = nums;
    sort(nsort.begin(), nsort.end());

    int si = 0, ei = nums.size() - 1;
    while (si < nums.size() && nums[si] == nsort[si]) si++;
    while (ei >= si && nums[ei] == nsort[ei]) ei--;

    return ei - si + 1;
  }
};
