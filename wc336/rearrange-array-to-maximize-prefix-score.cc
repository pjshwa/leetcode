using ll = long long;

class Solution {
public:
  int maxScore(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end(), greater<int>());
    vector<ll> P(n);
    P[0] = nums[0];
    for (int i = 1; i < n; i++) {
      P[i] = P[i - 1] + nums[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (P[i] > 0) ans++;
    }
    return ans;
      
  }
};
