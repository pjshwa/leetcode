class Solution {
public:
  int timeRequiredToBuy(vector<int>& tickets, int k) {
    int N = tickets.size();
    queue<int> Q; for (int i = 0; i < N; ++i) Q.push(i);

    for (int t = 1;; ++t) {
      int f = Q.front(); Q.pop();
      if (--tickets[f]) Q.push(f);
      else if (f == k) return t;
    }
    return -1;
  }
};
