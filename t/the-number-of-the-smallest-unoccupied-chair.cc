using pii = pair<int, int>;
const int MAXT = 1e5;

class Solution {
public:
  int smallestChair(vector<vector<int>>& times, int targetFriend) {
    int N = times.size(), ans;
    vector<tuple<int, int, int>> events;
    for (int i = 0; i < N; ++i) {
      events.push_back({times[i][0], 1, i});
      events.push_back({times[i][1], 0, i});
    }
    sort(events.begin(), events.end());

    priority_queue<int, vector<int>, greater<int>> vacant;
    for (int i = 0; i < N; ++i) vacant.push(i);
    vector<int> seats(N, -1);

    auto process_event = [&](int i) {
      auto& [t, o, idx] = events[i];
      if (o) {
        int seat = vacant.top(); vacant.pop();
        seats[idx] = seat;
        if (idx == targetFriend) ans = seat;
      } else {
        vacant.push(seats[idx]);
      }
    };

    int ei = 0, ez = events.size();
    for (int t = 1; t <= MAXT; ++t) {
      while (ei < ez && get<0>(events[ei]) == t) process_event(ei++);
    }
    return ans;
  }
};
