class Solution {
  void compress(vector<int>& a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
  }

public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    vector<int> xs; map<int, int> dt;
    for (auto& flower : flowers) {
      int s = flower[0], e = flower[1];
      dt[s] += 1; dt[e + 1] -= 1;
      xs.push_back(s); xs.push_back(e + 1);
    }
    compress(xs);

    int n = people.size();
    vector<int> ans(n, 0);

    vector<pair<int, int>> ps(n);
    for (int i = 0; i < n; i++) ps[i] = {people[i], i};
    sort(ps.begin(), ps.end());

    int cnt = 0, p = 0;
    for (int x : xs) {
      while (p < n) {
        auto [k, i] = ps[p];
        if (k >= x) break;
        ans[i] = cnt;
        p++;
      }
      cnt += dt[x];
    }
    return ans;
  }
};
