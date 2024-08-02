class Solution {
public:
  int minSwaps(vector<int>& nums) {
    int N = nums.size();
    vector<int> P(2 * N + 1);
    for (int i = 1; i <= 2 * N; ++i) P[i] = P[i - 1] + (nums[(i - 1) % N] == 1);

    int ocnt = P[N], ans = N;
    for (int i = ocnt; i <= 2 * N; ++i) ans = min(ans, ocnt - (P[i] - P[i - ocnt]));
    return ans;
  }
};
