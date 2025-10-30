class Solution {
public:
  int minNumberOperations(vector<int>& target) {
    int ans = target[0], N = target.size();
    for (int i = 1; i < N; ++i) ans += max(0, target[i] - target[i - 1]);
    return ans;
  }
};
