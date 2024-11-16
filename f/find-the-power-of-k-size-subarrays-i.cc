class Solution {
public:
  vector<int> resultsArray(vector<int>& nums, int k) {
    int N = nums.size();
    vector<int> streaks(N, 1);
    for (int i = 1; i < N; i++) {
      if (nums[i] == nums[i - 1] + 1) streaks[i] = streaks[i - 1] + 1;
    }

    vector<int> res;
    for (int i = k - 1; i < N; ++i) {
      int val = -1;
      if (streaks[i] >= k) val = nums[i];
      res.push_back(val);
    }
    return res;
  }
};
