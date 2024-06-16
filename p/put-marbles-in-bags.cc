class Solution {
public:
  long long putMarbles(vector<int>& weights, int k) {
    int N = weights.size();

    priority_queue<int> pq_max;
    priority_queue<int, vector<int>, greater<int>> pq_min;
    for (int i = 0; i < N - 1; i++) {
      int w = weights[i] + weights[i + 1];
      pq_max.push(w); pq_min.push(w);
    }

    long long mmax = 0, mmin = 0;
    while (--k) {
      mmax += pq_max.top(); pq_max.pop();
      mmin += pq_min.top(); pq_min.pop();
    }
    return mmax - mmin;
  }
};
