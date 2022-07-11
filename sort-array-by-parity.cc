class Solution {
public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    vector<int> e;
    queue<int> o;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] % 2 == 0) e.push_back(nums[i]);
      else o.push(nums[i]);
    }
    while (!o.empty()) {
      e.push_back(o.front());
      o.pop();
    }
    return e;
  }
};
