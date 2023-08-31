const int INF = 0x3f3f3f3f;

class Solution {
public:
  int minTaps(int n, vector<int>& ranges) {
    vector<int> endpoints[n + 1];
    for (int i = 0; i <= n; i++) {
      int s = max(0, i - ranges[i]);
      int e = i + ranges[i];
      endpoints[s].push_back(e);
    }

    int reach = 0, ans = 0;
    priority_queue<int> wait;
    for (int i = 0; i < n; i++) {
      for (int e : endpoints[i]) wait.push(e);

      if (reach < i) return -1;
      else if (reach == i) {
        if (wait.empty()) return -1;
        else {
          reach = max(reach, wait.top());
          wait.pop();
          ans++;
        }
      }
    }

    return reach >= n ? ans : -1;
  }
};
