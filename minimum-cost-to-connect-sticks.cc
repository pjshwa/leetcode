class Solution {
public:
  int connectSticks(vector<int>& sticks) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int e : sticks) pq.push(e);

    int ans = 0;
    while (pq.size() > 1) {
      int x = pq.top(); pq.pop();
      int y = pq.top(); pq.pop();
      ans += x + y;
      pq.push(x + y);
    }
    return ans;
  }
};
