class Solution {
  int C(int n, int k) {
    int ret = 1;
    for (int i = 1; i <= k; ++i) {
      ret *= n - i + 1;
      ret /= i;
    }
    return ret;
  }

public:
  string kthSmallestPath(vector<int>& destination, int k) {
    int tv = destination[0], th = destination[1];

    string ans = ""; int it = tv + th;
    while (it--) {
      // Check if we can append 'H' here
      if (k <= C(it, tv)) {
        ans += 'H';
        --th;
      }
      else {
        ans += 'V';
        k -= C(it, tv);
        --tv;
      }
    }

    return ans;
  }
};
