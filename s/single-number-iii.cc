class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    map<int, int> t;
    for (int e : nums) ++t[e];

    vector<int> ans;
    for (auto& [k, v] : t) if (v == 1) ans.push_back(k);
    return ans;
  }
};
