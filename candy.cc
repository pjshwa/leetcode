class Solution {
public:
  int candy(vector<int>& ratings) {
    int N = ratings.size();

    queue<int> q;
    vector<int> cdist(N, 0);
    for (int i = 0; i < N; ++i) {
      bool pit = (i == 0 || ratings[i - 1] >= ratings[i]);
      pit &= (i == N - 1 || ratings[i + 1] >= ratings[i]);
      if (pit) cdist[i] = 1, q.push(i);
    }

    while (!q.empty()) {
      int v = q.front(); q.pop();

      for (int u : {v - 1, v + 1}) {
        if (u < 0 || u >= N) continue;
        if (ratings[u] <= ratings[v]) continue;

        cdist[u] = cdist[v] + 1;
        q.push(u);
      }
    }

    return accumulate(cdist.begin(), cdist.end(), 0);
      
  }
};
