class Solution {
public:
  int countDays(int days, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());
    int ans = 0, last = 0;
    for (auto& m : meetings) {
      int start = m[0], end = m[1];
      ans += max(0, start - last - 1);
      last = max(last, end);
    }
    ans += days - last;
    return ans;
  }
};
