class Solution {
  int n, cnt = 0, ok = 0, L;
  vector<int> V, A;

  void dfs(int i) {
    if (cnt == n) {
      ok = 1;
      return;
    }
    if (ok || i >= L) return;

    if (V[i]) return dfs(i + 1);
    for (int j = n; j >= 2; --j) {
      if (A[j]) continue;
      if (i + j >= L || V[i + j]) continue;
      A[j] = 1; V[i] = V[i + j] = j; ++cnt;
      dfs(i + 1); if (ok) return;
      A[j] = 0; V[i] = V[i + j] = 0; --cnt;
    }
    if (!A[1]) {
      A[1] = 1; V[i] = 1; ++cnt;
      dfs(i + 1); if (ok) return;
      A[1] = 0; V[i] = 0; --cnt;
    }
  }

public:
  vector<int> constructDistancedSequence(int n) {
    this->n = n; L = 2 * n - 1;
    V.assign(L, 0);
    A.resize(n + 1);

    dfs(0);
    return V;
  }
};
