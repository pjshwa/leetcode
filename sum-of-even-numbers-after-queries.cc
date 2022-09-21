class Solution {
public:
  vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> ans;
    int cur = 0;
    for (int num : nums) {
      if (num % 2 == 0) cur += num;
    }

    for (auto& query : queries) {
      int val = query[0], idx = query[1];

      int pre = nums[idx];
      int nxt = pre + val;
      
      if (pre % 2 == 0) cur -= pre;
      if (nxt % 2 == 0) cur += nxt;

      ans.push_back(cur);
      nums[idx] = nxt;
    }

    return ans;
  }
};
