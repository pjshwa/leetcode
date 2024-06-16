const int INF = 1e9 + 7;

class Solution {
public:
  int minimumDeviation(vector<int>& nums) {
    priority_queue<int> px;
    int mn = INF;
    for (int num : nums) {
      int rnum = num % 2 ? num * 2 : num;
      px.push(rnum);
      mn = min(mn, rnum);
    }

    int ans = px.top() - mn;
    while (px.top() % 2 == 0) {
      int x = px.top();
      px.pop();

      ans = min(ans, x - mn);
      mn = min(mn, x / 2);
      px.push(x / 2);
    }

    return min(ans, px.top() - mn);
  }
};
