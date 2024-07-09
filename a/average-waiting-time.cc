class Solution {
public:
  double averageWaitingTime(vector<vector<int>>& customers) {
    int ctime = 0; double wtime = 0;
    for (auto& c : customers) {
      int a = c[0], t = c[1];
      if (a < ctime) wtime += ctime - a;
      wtime += t;
      ctime = max(a, ctime) + t;
    }
    return wtime / customers.size();
  }
};
