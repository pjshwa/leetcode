#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

class Solution {
public:
  vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    int N = servers.size(), M = tasks.size();
    vector<int> ans(M); queue<pii> tq;
    priority_queue<ll, vector<ll>, greater<ll>> tts;
    for (int j = 0; j < M; ++j) tts.emplace(j);

    using T = tuple<ll, int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq_wait;
    priority_queue<T, vector<T>, greater<T>> pq_run;
    for (int i = 0; i < N; ++i) pq_wait.emplace(servers[i], i);
    while (!tts.empty()) {
      ll ct = tts.top(); tts.pop();
      if (ct < M) tq.emplace(ct, tasks[ct]);
      while (!pq_run.empty() && get<0>(pq_run.top()) <= ct) {
        auto [_, w, i] = pq_run.top(); pq_run.pop();
        pq_wait.emplace(w, i);
      }
      while (!tq.empty() && !pq_wait.empty()) {
        auto [j, e] = tq.front(); tq.pop();
        auto [w, i] = pq_wait.top(); pq_wait.pop();
        ans[j] = i; ll nt = ct + e;
        pq_run.emplace(nt, w, i);
        if (nt >= M) tts.emplace(nt);
      }
    }
    return ans;
  }
};
