class Solution {
public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());

    vector<int> R(n);
    priority_queue<int, vector<int>, greater<int>> wait;

    using T = pair<long long, int>;
    priority_queue<T, vector<T>, greater<T>> run;
    for (int i = 0; i < n; ++i) wait.push(i);

    for (auto& mv : meetings) {
      int ms = mv[0], me = mv[1];
      while (!run.empty() && run.top().first <= ms) {
        auto [ce, t] = run.top(); run.pop();
        wait.push(t);
      }

      if (wait.empty()) {
        auto [ce, t] = run.top(); run.pop();
        run.push({me + (ce - ms), t});
        ++R[t];
      }
      else {
        int t = wait.top(); wait.pop();
        run.push({me, t});
        ++R[t];
      }
    }

    int maxv = *max_element(R.begin(), R.end());
    for (int i = 0; i < n; ++i) {
      if (R[i] == maxv) return i;
    }
    return -1;
  }
};
