class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    int indegree[n]; memset(indegree, 0, sizeof indegree);
    for (auto &e : edges) indegree[e[1]]++;

    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (indegree[i] == 0) ans.push_back(i);
    }
    return ans;
  }
};
