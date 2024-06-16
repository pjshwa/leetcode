class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size() + nums2.size();
    if (n & 1) {
      return findKth(nums1, 0, nums2, 0, n / 2 + 1);
    } else {
      return (findKth(nums1, 0, nums2, 0, n / 2) + findKth(nums1, 0, nums2, 0, n / 2 + 1)) / 2.0;
    }
  }

  int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
    if (nums1.size() - i > nums2.size() - j) {
      return findKth(nums2, j, nums1, i, k);
    }
    if (nums1.size() == i) {
      return nums2[j + k - 1];
    }
    if (k == 1) {
      return min(nums1[i], nums2[j]);
    }
    int pa = min(i + k / 2, (int)nums1.size());
    int pb = j + k - pa + i;
    if (nums1[pa - 1] < nums2[pb - 1]) {
      return findKth(nums1, pa, nums2, j, k - pa + i);
    } else if (nums1[pa - 1] > nums2[pb - 1]) {
      return findKth(nums1, i, nums2, pb, k - pb + j);
    } else {
      return nums1[pa - 1];
    }
  }
};
