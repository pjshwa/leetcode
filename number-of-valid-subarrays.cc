class Solution {
public:
  int validSubarrays(vector<int>& nums) {
    stack<int> s; int ans = 0;
    for (int e : nums) {
      while (!s.empty() && s.top() > e) s.pop();
      s.push(e);
      ans += s.size();
    }
    return ans;
  }
};
