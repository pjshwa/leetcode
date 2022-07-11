class Solution {
public:
  int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[1] < b[1];
    });
    priority_queue<int> pq;

    int ctime = 0;
    for (auto& course : courses) {
      int di = course[0], li = course[1];
      if (ctime + di <= li) {
        ctime += di;
        pq.push(di);
      }
      else if (!pq.empty() && pq.top() > di) {
        ctime += di - pq.top();
        pq.pop();
        pq.push(di);
      }

    }

    return pq.size();
  }
};
