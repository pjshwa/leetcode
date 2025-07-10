class Solution {
public:
  int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
    int ans = 0, N = startTime.size();

    vector<int> PL(N + 10, 0), PR(N + 10, 0);
    PL[1] = startTime[0];
    for (int i = 2; i <= N; ++i) {
      PL[i] = max(PL[i - 1], startTime[i - 1] - endTime[i - 2]);
    }
    PR[N] = eventTime - endTime.back();
    for (int i = N - 1; i >= 1; --i) {
      PR[i] = max(PR[i + 1], startTime[i] - endTime[i - 1]);
    }

    for (int i = 1; i <= N; ++i) {
      int block = endTime[i - 1] - startTime[i - 1], slot = max(PL[i - 1], PR[i + 1]);
      int vac_s = i > 1 ? endTime[i - 2] : 0, vac_e = i < N ? startTime[i] : eventTime;
      int vac = vac_e - vac_s;
      if (slot >= block) ans = max(ans, vac);
      else ans = max(ans, vac - block);
    }
    return ans;
  }
};
