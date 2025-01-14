class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int T[51]{}, N = A.size(), cnt = 0;
    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
      if (++T[A[i]] == 0) ++cnt;
      if (--T[B[i]] == 0) ++cnt;
      C[i] = cnt;
    }
    return C;
  }
};
