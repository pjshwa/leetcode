class Solution {
  int cdist[10000], ban[10000];

public:
  int openLock(vector<string>& deadends, string target) {
    memset(cdist, 0x3f, sizeof(cdist));
    memset(ban, 0, sizeof(ban));
    for (auto& e : deadends) ban[stoi(e)] = 1;

    queue<int> q;
    if (!ban[0]) q.push(0), cdist[0] = 0;

    int T = stoi(target);
    while (!q.empty()) {
      int t = q.front(); q.pop();
      if (t == T) return cdist[t];

      int w = 1;
      for (int i = 0; i < 4; ++i) {
        int d = (t / w) % 10;
        for (int nd : {(d + 1) % 10, (d + 9) % 10}) {
          int nt = t + (nd - d) * w;
          if (ban[nt] || cdist[nt] <= cdist[t] + 1) continue;
          cdist[nt] = cdist[t] + 1; q.push(nt);
        }
        w *= 10;
      }
    }

    return -1;
  }
};
