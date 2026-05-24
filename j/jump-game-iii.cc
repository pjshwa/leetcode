class Solution {
public:
  bool canReach(vector<int>& arr, int start) {
    int N = arr.size();
    queue<int> q; vector<bool> visited(N, false);
    q.push(start); visited[start] = true;
    while (!q.empty()) {
      int i = q.front(); q.pop();
      if (arr[i] == 0) return true;
      if (i - arr[i] >= 0 && !visited[i - arr[i]]) {
        q.push(i - arr[i]); visited[i - arr[i]] = true;
      }
      if (i + arr[i] < N && !visited[i + arr[i]]) {
        q.push(i + arr[i]); visited[i + arr[i]] = true;
      }
    }
    return false;
  }
};
