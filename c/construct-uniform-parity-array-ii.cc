class Solution {
public:
  bool uniformArray(vector<int>& nums1) {
    int all_even = 1;
    for (int e : nums1) {
      if (e & 1) all_even = 0;
    }
    if (all_even) return true;

    sort(nums1.begin(), nums1.end());

    int flag = 0;
    for (int e : nums1) {
      if (e & 1) flag = 1;
      else if (!flag) return false;
    }
    return true;
  }
};
