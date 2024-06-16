const int INF = 0x3f3f3f3f;

class Solution {
public:
  int closestToTarget(vector<int>& arr, int target) {
    int N = arr.size();

    // count of zeros in each bit
    int P[N + 1][30]; memset(P, 0, sizeof P);

    for (int i = 0; i < N; ++i) {
      for (int b = 0; b < 30; ++b) {
        int bit = (arr[i] & (1 << b)) > 0;
        P[i + 1][b] = P[i][b] + (bit == 0);
      }
    }

    int ans = INF;
    for (int i = 1; i <= N; ++i) {
      int l = i, r = N + 1;
      while (l < r) {
        int mid = (l + r) / 2;

        int num = 0;
        for (int b = 0; b < 30; ++b) {
          int zcnt = P[mid][b] - P[i - 1][b];
          if (zcnt == 0) num |= (1 << b);
        }

        if (num > target) l = mid + 1;
        else r = mid;
      }

      // check adjacent two numbers: l and l - 1
      for (int f : {l - 1, l}) {
        if (f < i || f > N) continue;
        int num = 0;
        for (int b = 0; b < 30; ++b) {
          int zcnt = P[f][b] - P[i - 1][b];
          if (zcnt == 0) num |= (1 << b);
        }
        ans = min(ans, abs(num - target));
      }
    }

    return ans;
  }
};
