class Solution {
public:
  int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
    int N = status.size();
    vector<int> visited(N, 0), hasReached(N, 0);
    vector<vector<int>> graph(N);
    for (int i = 0; i < N; ++i) {
      for (int box : containedBoxes[i]) graph[i].push_back(box);
    }

    function<bool(int)> isAvail = [&](int box) {
      return status[box] == 1 && hasReached[box] == 1;
    };

    queue<int> q;
    for (int box : initialBoxes) {
      hasReached[box] = 1;
      if (isAvail(box)) {
        q.push(box);
        visited[box] = 1;
      }
    }

    while (!q.empty()) {
      int box = q.front(); q.pop();
      for (int nbox : keys[box]) {
        if (visited[nbox]) continue;
        status[nbox] = 1;
        if (isAvail(nbox)) {
          q.push(nbox);
          visited[nbox] = 1;
        }
      }
      for (int nbox : graph[box]) {
        if (visited[nbox]) continue;
        hasReached[nbox] = 1;
        if (isAvail(nbox)) {
          q.push(nbox);
          visited[nbox] = 1;
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) ans += visited[i] * candies[i];
    return ans;
  }
};
