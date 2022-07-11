using pii = pair<int, int>;

class Solution {
  int d[20'001];
public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; i++) pq.push({ratings[i], i});

    memset(d, 0, sizeof(d));
    while (!pq.empty()) {
      auto [h, i] = pq.top();
      pq.pop();

      d[i] = 1;
      if (i > 0 && ratings[i - 1] < h) d[i] = max(d[i], d[i - 1] + 1);
      if (i < n - 1 && ratings[i + 1] < h) d[i] = max(d[i], d[i + 1] + 1);
    }

    return accumulate(d, d + n, 0);
  }
};
