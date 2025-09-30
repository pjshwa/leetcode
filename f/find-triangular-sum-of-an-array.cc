class Solution {
public:
  int triangularSum(vector<int>& nums) {
    vector<int> E = nums, nE;
    while (E.size() > 1) {
      for (int i = 1; i < E.size(); ++i) {
        nE.push_back((E[i] + E[i - 1]) % 10);
      }
      E = nE;
      nE.clear();
    }
    return E.back();
  }
};
