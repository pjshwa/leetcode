class Solution {
public:
  bool canArrange(vector<int>& arr, int k) {
    vector<int> R(k);
    for (int e : arr) ++R[(e % k + k) % k];

    for (int r = 1; r < k; ++r) {
      if (r == k - r) {
        if (R[r] % 2) return false;
      }
      else if (R[r] != R[k - r]) return false;
    }
    return R[0] % 2 == 0;
  }
};
