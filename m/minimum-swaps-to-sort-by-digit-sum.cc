int dsum(int n) {
  int ret = 0;
  while (n) {
    ret += n % 10;
    n /= 10;
  }
  return ret;
}

int cmp(int a, int b) {
  if (dsum(a) != dsum(b)) return dsum(a) < dsum(b);
  return a < b;
}

class Solution {
public:
  int minSwaps(vector<int>& nums) {
    auto numsB = nums;
    sort(numsB.begin(), numsB.end(), cmp);

    int ans = 0, N = nums.size(); map<int, int> idx;
    for (int i = 0; i < N; ++i) idx[nums[i]] = i;
    vector<int> nxt(N);
    for (int i = 0; i < N; ++i) nxt[i] = idx[numsB[i]];

    vector<bool> vis(N, false);
    for (int i = 0; i < N; ++i) {
      if (vis[i]) continue;
      int j = i, sz = 0;
      while (!vis[j]) {
        vis[j] = true;
        j = nxt[j];
        ++sz;
      }
      ans += sz - 1;
    }
    return ans;
  }
};
