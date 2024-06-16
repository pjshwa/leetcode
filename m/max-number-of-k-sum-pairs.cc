class Solution {
public:
  int maxOperations(vector<int>& nums, int k) {
    map<int, int> t;
    for (int i = 0; i < nums.size(); i++) t[nums[i]]++;

    int ans = 0;
    for (auto& [key, val] : t) {
      if (k - key < key) break;
      else if (k == 2 * key) ans += val / 2;
      else {
        int add = min(val, t[k - key]);
        ans += add;
      }
    }

    return ans;
  }
};
