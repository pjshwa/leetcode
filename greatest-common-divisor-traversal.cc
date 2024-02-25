const int MAXN = 1e5;

class Solution {
public:
  bool canTraverseAllPairs(vector<int>& nums) {
    int N = nums.size();
    if (N == 1) return true;

    sort(nums.begin(), nums.end());
    if (nums[0] == 1) return false;

    vector<int> parent(2 * MAXN + 1), usz(2 * MAXN + 1, 0);
    iota(parent.begin(), parent.end(), 0);
    fill(usz.begin(), usz.begin() + N, 1);

    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x == y) return;
      if (usz[x] < usz[y]) swap(x, y);
      parent[y] = x; usz[x] += usz[y];
    };
    auto UnionD = [&](int x, int d) {
      if (d > 1) Union(x, MAXN + d);
    };

    for (int i = 0; i < N; i++) {
      int e = nums[i];
      for (int d = 1; d * d <= e; d++) {
        if (e % d) continue;
        UnionD(i, d); UnionD(i, e / d);
      }
    }

    return usz[Find(0)] == N;
  }
};
