class Solution {
public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[0] < b[0];
    });

    int ans = 0; priority_queue<int, vector<int>, greater<int>> use;
    for (auto& interval : intervals) {
      while (!use.empty() && use.top() <= interval[0]) use.pop();
      use.push(interval[1]);
      ans = max(ans, (int)use.size());
    }
    return ans;
  }
};
