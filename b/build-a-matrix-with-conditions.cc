const int MAX = 400;

class Solution {
public:
  vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    // decide the order of numbers on rows
    int rowIndex[k + 1];
    {
      vector<int> adj[MAX + 1]; int indegree[MAX + 1]{};
      for (auto c : rowConditions) {
        int u = c[0], v = c[1];
        adj[u].push_back(v); indegree[v]++;
      }

      queue<int> q;
      for (int i = 1; i <= k; i++) {
        if (!indegree[i]) q.push(i);
      }

      for (int i = 0; i < k; i++) {
        if (q.empty()) return {};

        int v = q.front(); q.pop();
        rowIndex[v] = i;

        for (int u : adj[v]) {
          if (!--indegree[u]) q.push(u);
        }
      }
    }

    // decide the order of numbers on columns
    int colIndex[k + 1];
    {
      vector<int> adj[MAX + 1]; int indegree[MAX + 1]{};
      for (auto c : colConditions) {
        int u = c[0], v = c[1];
        adj[u].push_back(v); indegree[v]++;
      }

      queue<int> q;
      for (int i = 1; i <= k; i++) {
        if (!indegree[i]) q.push(i);
      }

      for (int i = 0; i < k; i++) {
        if (q.empty()) return {};

        int v = q.front(); q.pop();
        colIndex[v] = i;

        for (int u : adj[v]) {
          if (!--indegree[u]) q.push(u);
        }
      }
    }

    vector<vector<int>> ret;
    for (int i = 0; i < k; i++) ret.push_back(vector<int>(k, 0));
    for (int i = 1; i <= k; i++) {
      ret[rowIndex[i]][colIndex[i]] = i;
    }
    return ret;
  }
};
