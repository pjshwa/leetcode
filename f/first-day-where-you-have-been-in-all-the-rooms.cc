class Solution {
public:
  int firstDayBeenInAllRooms(vector<int>& nextVisit) {
    int N = nextVisit.size();

    vector<int> vis(N);
    int c = 0, tot = 0, it = 0;
    while (tot < N) {
      ++it;

      if (vis[c] == 0) ++tot;
      vis[c] += 1;
      if (vis[c] & 1) c = nextVisit[c];
      else c = (c + 1) % N;
    }
    return it - 1;
  }
};
