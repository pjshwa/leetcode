class Solution {
public:
  int minimumSize(vector<int>& nums, int maxOperations) {
    int l = 1, r = *max_element(nums.begin(), nums.end());
    while (l < r) {
      int m = (l + r) / 2, cnt = 0;
      for (int e : nums) {
        if (e > m) cnt += (e + m - 1) / m - 1;
      }
      if (cnt > maxOperations) l = m + 1;
      else r = m;
    }
    return l;
  }
};
