class Solution {
public:
  vector<int> sortEvenOdd(vector<int>& nums) {
    int n = nums.size();
    vector<int> o, e;
    for (int i = 0; i < n; i++) {
      if (i & 1) o.push_back(nums[i]);
      else e.push_back(nums[i]);
    }
    sort(e.begin(), e.end());
    sort(o.begin(), o.end());
    reverse(o.begin(), o.end());

    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (i & 1) ans.push_back(o[i / 2]);
      else ans.push_back(e[i / 2]);
    }

    return ans;
  }
};
