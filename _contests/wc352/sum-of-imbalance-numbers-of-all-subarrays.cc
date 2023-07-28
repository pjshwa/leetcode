const int MAX = 1000;

class Solution {
  int D[MAX + 10];

public:
  int sumImbalanceNumbers(vector<int>& nums) {
    int N = nums.size(), ans = 0;
    for (int l = 0; l < N; l++) {
      memset(D, 0, sizeof(D));
      D[nums[l]]++;

      int run = 0;
      for (int j = l + 1; j < N; j++) {
        int e = nums[j];
        if (D[e] == 0) {
          run++;
          run -= D[e - 1];
          run -= D[e + 1];
          D[e] = 1;
        }
        ans += run;
      }
    }
    return ans;
  }
};
