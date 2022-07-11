class Solution {
  int indegree[1001], outdegree[1001];
public:
  int findJudge(int n, vector<vector<int>>& trust) {
    memset(indegree, 0, sizeof(indegree));
    memset(outdegree, 0, sizeof(outdegree));

    for (auto& v : trust) {
      outdegree[v[0]]++;
      indegree[v[1]]++;
    }

    for (int i = 1; i <= n; i++) {
      if (indegree[i] == n - 1 && outdegree[i] == 0) return i;
    }

    return -1;
  }
};
