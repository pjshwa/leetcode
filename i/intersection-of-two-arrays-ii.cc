class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> c1, c2;
    for (int e : nums1) ++c1[e];
    for (int e : nums2) ++c2[e];

    vector<int> ans;
    for (auto& [k, v] : c1) {
      int t = min(c1[k], c2[k]);
      while (t--) ans.push_back(k);
    }
    return ans;
  }
};
