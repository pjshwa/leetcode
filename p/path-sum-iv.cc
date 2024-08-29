const int MAXN = 15;

class Solution {
  vector<int> adj[MAXN];
  int A[MAXN], ans = 0;

  void dfs(int v, int acc) {
    if (adj[v].empty()) {
      ans += acc + A[v];
      return;
    }
    for (int u : adj[v]) dfs(u, acc + A[v]);
  }

public:
  int pathSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int N = nums.size();
    for (int i = 0; i < N; ++i) A[i] = nums[i] % 10;

    for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) {
      int il = nums[i] / 100, jl = nums[j] / 100;
      if (il + 1 != jl) continue;

      int ip = (nums[i] / 10) % 10, jp = (nums[j] / 10) % 10;
      if (ip * 2 - 1 != jp && ip * 2 != jp) continue;
      adj[i].push_back(j);
    }

    dfs(0, 0);
    return ans;
  }
};
