class Solution {
public:
  int findSmallestInteger(vector<int>& nums, int value) {
    vector<int> C(value);
    for (int e : nums) {
      int m;
      if (e < 0) m = (value - (-e % value)) % value;
      else m = e % value;
      ++C[m];
    }
    for (int i = 0;; ++i) {
      int m = i % value;
      if (C[m] == 0) return i;
      --C[m];
    }
  }
};
