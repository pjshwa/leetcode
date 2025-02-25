const int MOD = 1e9 + 7;

class Solution {
public:
  int numOfSubarrays(vector<int>& arr) {
    int C[2] = {1, 0}, ans = 0, sw = 0;
    for (int e : arr) {
      if (e & 1) sw ^= 1;
      ans = (ans + C[1 - sw]) % MOD;
      ++C[sw];
    }
    return ans;
  }
};
