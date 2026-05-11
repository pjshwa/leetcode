class Solution {
public:
  vector<int> separateDigits(vector<int>& nums) {
    vector<int> ans;
    for (int e : nums) {
      vector<int> P;
      while (e) P.push_back(e % 10), e /= 10;
      reverse(P.begin(), P.end());
      ans.insert(ans.end(), P.begin(), P.end());
    }
    return ans;
  }
};
