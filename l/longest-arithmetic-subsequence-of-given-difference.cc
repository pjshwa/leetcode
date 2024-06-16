class Solution {
public:
  int longestSubsequence(vector<int>& arr, int difference) {
    map<int, int> d; int ans = 1;
    for (int e : arr) {
      d[e] = max(d[e], d[e - difference] + 1);
      ans = max(ans, d[e]);
    }
    return ans;
  }
};
