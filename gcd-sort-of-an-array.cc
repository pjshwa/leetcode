const int MAXV = 1e5;

class Solution {
public:
  bool gcdSort(vector<int>& nums) {
    int parent[MAXV + 1];
    iota(parent, parent + MAXV + 1, 0);

    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x != y) parent[y] = x;
    };

    for (int e : nums) {
      for (int i = 2; i * i <= e; i++) {
        if (e % i == 0) {
          Union(i, e);
          Union(e / i, e);
        }
      }
    }

    vector<int> Gi[MAXV + 1], Ge[MAXV + 1];
    for (int i = 0; i < nums.size(); i++) {
      int e = nums[i]; int g = Find(e);
      Gi[g].push_back(i);
      Ge[g].push_back(e);
    }

    for (int i = 1; i <= MAXV; i++) {
      int z = Gi[i].size();
      if (z == 0) continue;
      
      sort(Ge[i].begin(), Ge[i].end());
      for (int j = 0; j < z; j++) {
        nums[Gi[i][j]] = Ge[i][j];
      }
    }

    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    return nums == sorted;
  }
};
