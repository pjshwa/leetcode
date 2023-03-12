class Solution {
public:
  long long beautifulSubarrays(vector<int>& nums) {

    long long ans = 0;
    map<int, int> t;
    t[0] = 1;

    int x = 0;
    for (int i = 0; i < nums.size(); i++) {
      x ^= nums[i];
      ans += t[x];
      t[x]++;
    }

    return ans;
  }
};
