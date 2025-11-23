class Solution {
public:
  int maxSumDivThree(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 3 == 0) return sum;

    vector<int> R[3]; int sub = sum;
    for (int e : nums) R[e % 3].push_back(e);
    sort(R[1].begin(), R[1].end());
    sort(R[2].begin(), R[2].end());

    if (sum % 3 == 1) {
      if (R[1].size() >= 1) sub = min(sub, R[1][0]);
      if (R[2].size() >= 2) sub = min(sub, R[2][0] + R[2][1]);
    } else {
      if (R[2].size() >= 1) sub = min(sub, R[2][0]);
      if (R[1].size() >= 2) sub = min(sub, R[1][0] + R[1][1]);
    }
    return sum - sub;
  }
};
