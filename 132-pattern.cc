class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    int N = nums.size();

    int L[N]; L[0] = nums[0];
    for (int i = 1; i < N; ++i) L[i] = min(L[i - 1], nums[i]);

    stack<int> S; S.push(N - 1);
    for (int j = N - 2; j >= 1; --j) {
      int lmin = L[j - 1];
      while (!S.empty() && nums[S.top()] <= lmin) S.pop();

      int rmin = S.empty() ? INT_MAX : nums[S.top()];
      if (nums[j] > rmin) return true;

      if (S.empty() || nums[j] < nums[S.top()]) S.push(j);
    }

    return false;
  }
};
