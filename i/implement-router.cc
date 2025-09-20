const int MAXN = 2e5;

class Router {
  vector<int> by_d[MAXN + 1];
  int dsi[MAXN + 1];
  set<tuple<int, int, int>> packets;
  queue<tuple<int, int, int>> packets_q;
  int mint = 0, memoryLimit;

public:
  Router(int memoryLimit) {
    this->memoryLimit = memoryLimit;
    memset(dsi, 0, sizeof dsi);
  }

  bool addPacket(int source, int destination, int timestamp) {
    if (packets.count({source, destination, timestamp})) return false;

    packets.insert({source, destination, timestamp});
    packets_q.push({source, destination, timestamp});
    by_d[destination].push_back(timestamp);

    if (packets_q.size() > memoryLimit) forwardPacket();
    return true;
  }

  vector<int> forwardPacket() {
    if (packets_q.empty()) return {};

    auto [s, d, t] = packets_q.front(); packets_q.pop();
    packets.erase({s, d, t});
    mint = max(mint, t);
    ++dsi[d];
    return {s, d, t};
  }

  int getCount(int destination, int startTime, int endTime) {
    int mini = dsi[destination];
    auto itl = lower_bound(
      by_d[destination].begin() + mini,
      by_d[destination].end(),
      startTime
    );
    auto itu = upper_bound(
      by_d[destination].begin() + mini,
      by_d[destination].end(),
      endTime
    );
    return itu - itl;
  }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
