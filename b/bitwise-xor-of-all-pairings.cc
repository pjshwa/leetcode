class Solution {
public:
  int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int N = nums1.size(), M = nums2.size(), ans = 0;
    if (N & 1) for (int e : nums2) ans ^= e;
    if (M & 1) for (int e : nums1) ans ^= e;
    return ans;
  }
};
