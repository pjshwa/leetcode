class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<int> P = nums;
    sort(P.begin(), P.end());

    vector<vector<int>> ans;
    do { ans.push_back(P); } while (next_permutation(P.begin(), P.end()));
    return ans;
  }
};
