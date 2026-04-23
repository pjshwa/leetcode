using ll = long long;

class Solution {
  map<int, ll> L, Ls, R, Rs;

public:
  vector<ll> distance(vector<int>& nums) {
    int N = nums.size();
    for (int i = 0; i < N; ++i) R[nums[i]] += i, Rs[nums[i]]++;

    vector<ll> ans(N);
    for (int i = 0; i < N; ++i) {
      int x = nums[i];
      ans[i] = R[x] - L[x] - (Rs[x] - Ls[x]) * i;
      L[x] += i, Ls[x]++;
      R[x] -= i, Rs[x]--;
    }
    return ans;
  }
};
