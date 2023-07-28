class Solution {
public:
  vector<int> findLonely(vector<int>& nums) {
    map<int, int> t;
    for (auto& n : nums) t[n]++;

    vector<int> ans;
    for (auto [k, v] : t) {
      if (!t.count(k - 1) && !t.count(k + 1) && v == 1) ans.push_back(k);
    }

    return ans;
  }
};