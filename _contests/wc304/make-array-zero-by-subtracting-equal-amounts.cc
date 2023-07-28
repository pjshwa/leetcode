class Solution {
public:
  int minimumOperations(vector<int>& nums) {
    set<int> u;
    for (int num : nums) {
      if (num > 0) u.insert(num);
    }
    return u.size();
  }
};
