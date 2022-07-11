class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int ci = 0, last, streak = 1;
    for (int i = 0; i < n; i++) {
      if (i == 0) last = nums[i];
      else if (nums[i] == last) streak++;
      else {
        if (streak >= 2) nums[ci] = nums[ci + 1] = last, ci += 2;
        else nums[ci] = last, ci++;

        streak = 1;
        last = nums[i];
      }
    }

    if (streak >= 2) nums[ci] = nums[ci + 1] = last, ci += 2;
    else nums[ci] = last, ci++;

    return ci;
  }
};
