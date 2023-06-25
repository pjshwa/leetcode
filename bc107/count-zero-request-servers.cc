
class Solution {
public:
  vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
    sort(logs.begin(), logs.end(), [](auto& a, auto& b) {
      return a[1] < b[1];
    });

    int lz = logs.size(), qz = queries.size(); vector<int> ans(qz);
    vector<pair<int, int>> V;
    for (int i = 0; i < qz; ++i) {
      V.emplace_back(queries[i], i);
    }
    sort(V.begin(), V.end());

    queue<pair<int, int>> Q; int i = 0;
    map<int, int> T;

    for (auto [q, idx] : V) {
      int s = q - x, e = q;
      while (i < lz && logs[i][1] <= e) {
        Q.emplace(logs[i][0], logs[i][1]);
        T[logs[i][0]]++;
        ++i;
      }
      while (!Q.empty() && Q.front().second < s) {
        auto [id, t] = Q.front(); Q.pop();
        if (--T[id] == 0) T.erase(id);
      }

      ans[idx] = n - T.size();
    }
    return ans;
  }
};
