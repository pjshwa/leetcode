class Solution {
public:
  long long pickGifts(vector<int>& gifts, int k) {
    priority_queue<int> pq;
    for (int e : gifts) pq.push(e);
    while (k--) {
      int v = pq.top(); pq.pop();
      pq.push(sqrt(v));
    }

    long long ans = 0;
    while (!pq.empty()) {
      ans += pq.top(); pq.pop();
    }
    return ans;
  }
};