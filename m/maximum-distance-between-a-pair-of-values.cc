class Solution {
public:
  int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int N = nums1.size(), M = nums2.size(), i = 0, ans = 0;
    for (int j = 0; j < M; ++j) {
      while (i < N && nums1[i] > nums2[j]) ++i;
      if (i < N) ans = max(ans, j - i);
    }
    return ans;
  }
};
