class Solution {
  vector<int> A, B;

  void srt(int l, int r) {
    if (l >= r) return;

    int m = (l + r) / 2;
    srt(l, m);
    srt(m + 1, r);
    mrg(l, r);
  }

  void mrg(int l, int r) {
    int m = (l + r) / 2;

    for (int lp = l, rp = m + 1, i = l; i <= r; i++) {
      if (lp > m) B[i] = A[rp++];
      else if (rp > r) B[i] = A[lp++];
      else if (A[lp] < A[rp]) B[i] = A[lp++];
      else B[i] = A[rp++];
    }

    for (int i = l; i <= r; i++) A[i] = B[i];
  }

public:
  vector<int> sortArray(vector<int>& nums) {
    int N = nums.size();
    A = nums, B = vector<int>(N);
    srt(0, N - 1);
    return A;
  }
};
