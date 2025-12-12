const int MAXT = 1e5;
using pii = pair<int, int>;

vector<string> split(const string &str, string delim) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(delim, start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));
    start = end + delim.size();
  }

  tokens.push_back(str.substr(start));
  return tokens;
}

class Solution {
public:
  vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
    // sort by timestamp, if same timestamp, "OFFLINE" before "MESSAGE"
    sort(events.begin(), events.end(),
         [](const vector<string>& a, const vector<string>& b) {
           int ts_a = stoi(a[1]), ts_b = stoi(b[1]);
           return ts_a == ts_b ? a[0] > b[0] : ts_a < ts_b;
         });

    vector<int> mentions(numberOfUsers, 0), online(numberOfUsers, 1);
    priority_queue<pii, vector<pii>, greater<pii>> offlineQueue;
    auto processEvent = [&](int i) {
      auto op = events[i][0];
      auto ts = stoi(events[i][1]);
      if (op == "MESSAGE") {
        auto ms_v = split(events[i][2], " ");
        for (auto& ms : ms_v) {
          if (ms == "ALL" || ms == "HERE") {
            for (int uid = 0; uid < numberOfUsers; ++uid) {
              if (ms == "ALL" || online[uid]) ++mentions[uid];
            }
          } else {
            int uid = stoi(ms.substr(2));
            ++mentions[uid];
          }
        }

      } else {
        auto uid = stoi(events[i][2]);
        online[uid] = 0;
        offlineQueue.push({ts + 60, uid});
      }
    };

    int ei = 0, eZ = events.size();
    for (int t = 1; t <= MAXT; ++t) {
      while (!offlineQueue.empty() && offlineQueue.top().first == t) {
        int uid = offlineQueue.top().second; offlineQueue.pop();
        online[uid] = 1;
      }
      while (ei < eZ && stoi(events[ei][1]) == t) processEvent(ei++);
    }
    return mentions;
  }
};
