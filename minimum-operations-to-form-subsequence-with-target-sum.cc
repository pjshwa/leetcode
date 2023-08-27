class Solution {
public:
  int minOperations(vector<int>& nums, int target) {
    int C[32]{};
    for (int e : nums) {
      for (int p = 0; p <= 30; p++) {
        if ((1 << p) == e) C[p]++;
      }
    }

    int ans = 0;
    for (int p = 0; p <= 30; p++) {
      if (target & (1 << p)) {

        if (C[p] == 0) {
          int np = p + 1;
          while (np <= 30 && C[np] == 0) np++;
          if (np == 31) return -1;

          C[np]--;
          for (int i = p; i < np; i++) C[i]++, ans++;
          C[p]++;
        }
        C[p]--;

      }

      C[p + 1] += C[p] / 2;
      C[p] %= 2;
    }

    return ans;
  }
};
