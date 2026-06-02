#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

class Solution {
public:
  int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    vector<int> A; vector<pii> B; int N = landStartTime.size(), M = waterStartTime.size();
    priority_queue<pii, vector<pii>, greater<>> pq;

    for (int i = 0; i < N; ++i) A.emplace_back(landStartTime[i] + landDuration[i]);
    for (int i = 0; i < M; ++i) {
      B.emplace_back(waterStartTime[i], waterDuration[i]);
      pq.emplace(waterStartTime[i] + waterDuration[i], waterStartTime[i]);
    }
    sort(A.begin(), A.end()); sort(B.begin(), B.end());

    int ans = INT_MAX, add = INT_MAX, i = 0;
    for (int e : A) {
      while (i < M && B[i].first <= e) add = min(add, B[i].second), ++i;
      if (add != INT_MAX) ans = min(ans, e + add);
      while (!pq.empty() && pq.top().second < e) pq.pop();
      if (!pq.empty()) ans = min(ans, pq.top().first);
    }

    A.clear(); B.clear();
    while (!pq.empty()) pq.pop();

    for (int i = 0; i < M; ++i) A.emplace_back(waterStartTime[i] + waterDuration[i]);
    for (int i = 0; i < N; ++i) {
      B.emplace_back(landStartTime[i], landDuration[i]);
      pq.emplace(landStartTime[i] + landDuration[i], landStartTime[i]);
    }
    sort(A.begin(), A.end()); sort(B.begin(), B.end());

    add = INT_MAX; i = 0;
    for (int e : A) {
      while (i < N && B[i].first <= e) add = min(add, B[i].second), ++i;
      if (add != INT_MAX) ans = min(ans, e + add);
      while (!pq.empty() && pq.top().second < e) pq.pop();
      if (!pq.empty()) ans = min(ans, pq.top().first);
    }

    return ans;
  }
};
