class Solution {
public:
  int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
    int N = nums1.size(), ans = 1;

    int d[N][2]; memset(d, 0, sizeof(d));
    d[0][0] = d[0][1] = 1;
    for (int i = 1; i < N; i++) {
      d[i][0] = max(d[i][0], nums1[i] >= nums1[i - 1] ? d[i - 1][0] + 1 : 1);
      d[i][0] = max(d[i][0], nums1[i] >= nums2[i - 1] ? d[i - 1][1] + 1 : 1);
      d[i][1] = max(d[i][1], nums2[i] >= nums2[i - 1] ? d[i - 1][1] + 1 : 1);
      d[i][1] = max(d[i][1], nums2[i] >= nums1[i - 1] ? d[i - 1][0] + 1 : 1);
      ans = max({ans, d[i][0], d[i][1]});
    }

    return ans;
  }
};
