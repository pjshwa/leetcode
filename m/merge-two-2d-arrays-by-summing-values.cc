class Solution {
public:
  vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    vector<vector<int>> res; int N1 = nums1.size(), N2 = nums2.size(), i1 = 0, i2 = 0;
    while (i1 < N1 && i2 < N2) {
      int id1 = nums1[i1][0], id2 = nums2[i2][0];
      if (id1 == id2) {
        int val1 = nums1[i1][1], val2 = nums2[i2][1];
        res.push_back({id1, val1 + val2});
        i1++; i2++;
      }
      else if (id1 < id2) res.push_back(nums1[i1++]);
      else res.push_back(nums2[i2++]);
    }
    while (i1 < N1) res.push_back(nums1[i1++]);
    while (i2 < N2) res.push_back(nums2[i2++]);
    return res;
  }
};
