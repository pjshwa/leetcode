class Solution {
public:
  string largestNumber(vector<int>& nums) {
    vector<string> nums_s; int N = nums.size();
    for (int i = 0; i < N; ++i) nums_s.push_back(to_string(nums[i]));
    sort(nums_s.begin(), nums_s.end(), [](string &a, string &b) {
      return a + b > b + a;
    });

    string ans = "";
    for (int i = 0; i < N; ++i) ans += nums_s[i];
    return ans[0] == '0' ? "0" : ans;
  }
};
