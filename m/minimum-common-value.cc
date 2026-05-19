class Solution {
public:
  int getCommon(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0, N = nums1.size(), M = nums2.size();
    while (i < N && j < M && nums1[i] != nums2[j]) {
      if (nums1[i] > nums2[j]) ++j;
      else ++i;
    }
    return i < N && j < M ? nums1[i] : -1;
  }
};
