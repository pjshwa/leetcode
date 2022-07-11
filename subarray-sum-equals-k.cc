class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    map<int, int> t;
    t[0] = 1;
    int dt = 0;

    int ans = 0;
    for (int num : nums) {
      dt += num;
      ans += t[dt - k];
      t[dt]++;
    }

    return ans;
  }
};
