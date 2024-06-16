class Solution {
public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    set<int> S1{nums1.begin(), nums1.end()}, S2{nums2.begin(), nums2.end()};

    vector<int> v1, v2;
    for (int e : S1) if (!S2.count(e)) v1.push_back(e);
    for (int e : S2) if (!S1.count(e)) v2.push_back(e);

    return {v1, v2};
  }
};
