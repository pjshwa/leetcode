class Solution {
public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    vector<int> A, B;
    for (int a1 : nums1) for (int a2 : nums2) A.push_back(a1 + a2);
    for (int b1 : nums3) for (int b2 : nums4) B.push_back(b1 + b2);
    sort(B.begin(), B.end());

    int cnt = 0;
    for (int a : A) {
      cnt += upper_bound(B.begin(), B.end(), -a) - lower_bound(B.begin(), B.end(), -a);
    }
    return cnt;
  }
};
