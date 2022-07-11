class Solution {
public:
  int majorityElement(vector<int>& nums) {
    map<int, int> t;
    for (int i : nums) {
      if (t.count(i)) t[i]++;
      else t[i] = 1;
    }
    for (auto& p : t) {
      if (p.second > nums.size() / 2) return p.first;
    }
    return -1;
  }
};
