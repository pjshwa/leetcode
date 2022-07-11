class Solution {
public:
  vector<int> maxScoreIndices(vector<int>& nums) {
    int lzc = 0, roc = accumulate(nums.begin(), nums.end(), 0);
    int mscore = lzc + roc;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) lzc++;
      else roc--;
      mscore = max(mscore, lzc + roc);
    }

    vector<int> ans;
    lzc = 0, roc = accumulate(nums.begin(), nums.end(), 0);
    int cscore = lzc + roc;
    if (cscore == mscore) ans.push_back(0);

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) lzc++;
      else roc--;
      cscore = lzc + roc;
      if (cscore == mscore) ans.push_back(i + 1);
    }

    return ans;
      
  }
};
