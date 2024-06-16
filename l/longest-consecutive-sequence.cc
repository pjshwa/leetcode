class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());

    int ans = 0;
    for (int num : nums) {
      if (s.count(num - 1)) continue;

      int cnum = num;
      while (s.count(cnum + 1)) cnum++;

      ans = max(ans, cnum - num + 1);
    }

    return ans;
  }
};
