const int INF = 0x3f3f3f3f;

class Solution {
public:
  vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
    int N = edges1.size() + 1, M = edges2.size() + 1;
    if (k == 0) return vector<int>(N, 1);

    vector<int> adj1[N], adj2[M];
    for (auto& e : edges1) adj1[e[0]].push_back(e[1]), adj1[e[1]].push_back(e[0]);
    for (auto& e : edges2) adj2[e[0]].push_back(e[1]), adj2[e[1]].push_back(e[0]);

    int reach = 0;
    vector<int> cdist1(N), cdist2(M); queue<int> Q;
    for (int s = 0; s < M; ++s) {
      fill(cdist2.begin(), cdist2.end(), k);
      Q.push(s); cdist2[s] = 0;
      while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : adj2[u]) {
          if (cdist2[v] != k) continue;
          cdist2[v] = cdist2[u] + 1, Q.push(v);
        }
      }
      int cnt = 0;
      for (int j = 0; j < M; ++j) cnt += cdist2[j] < k;
      reach = max(reach, cnt);
    }

    vector<int> ans(N);
    for (int s = 0; s < N; ++s) {
      fill(cdist1.begin(), cdist1.end(), k + 1);
      Q.push(s); cdist1[s] = 0;
      while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : adj1[u]) {
          if (cdist1[v] != k + 1) continue;
          cdist1[v] = cdist1[u] + 1, Q.push(v);
        }
      }
      int cnt = 0;
      for (int j = 0; j < N; ++j) cnt += cdist1[j] <= k;
      ans[s] = reach + cnt;
    }
    return ans;
  }
};
