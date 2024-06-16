class Solution {
  set<int> S;
  int N, goal, ans;
  vector<int> nums;

  void dfs1(int i, int acc) {
    if (i == N / 2) {
      S.insert(acc);
      return;
    }
    dfs1(i + 1, acc);
    dfs1(i + 1, acc + nums[i]);
  }

  void dfs2(int i, int acc) {
    if (i == N - N / 2) {
      auto it = S.lower_bound(goal - acc);
      if (it != S.end()) {
        ans = min(ans, abs(goal - acc - *it));
      }
      if (it != S.begin()) {
        ans = min(ans, abs(goal - acc - *prev(it)));
      }
      return;
    }
    dfs2(i + 1, acc);
    dfs2(i + 1, acc + nums[N - i - 1]);
  }

public:
  int minAbsDifference(vector<int>& nums, int goal) {
    this->nums = nums;
    this->goal = goal;

    int sum = accumulate(nums.begin(), nums.end(), 0);
    ans = abs(goal - sum);

    N = nums.size();

    dfs1(0, 0);
    dfs2(0, 0);
    return ans;
  }
};
