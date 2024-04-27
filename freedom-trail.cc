class Solution {
public:
  int findRotateSteps(string ring, string key) {
    int R = ring.size(), K = key.size();

    int cdist[K + 1][R];
    memset(cdist, 0x3f, sizeof(cdist)); cdist[0][0] = 0;

    queue<pair<int, int>> Q; Q.push({0, 0});
    while (!Q.empty()) {
      auto [k, r] = Q.front(); Q.pop();
      if (k == K) return cdist[k][r];

      for (int c : {r - 1, r + 1}) {
        int i = (c + R) % R;
        if (cdist[k][i] > cdist[k][r] + 1) {
          cdist[k][i] = cdist[k][r] + 1;
          Q.push({k, i});
        }
      }

      if (key[k] == ring[r]) {
        if (k < K && cdist[k + 1][r] > cdist[k][r] + 1) {
          cdist[k + 1][r] = cdist[k][r] + 1;
          Q.push({k + 1, r});
        }
      }
    }

    return -1;
  }
};

