class Solution {
public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int N = mat.size(), M = mat[0].size();
    vector<int> rcnt(N), ccnt(M), vr(N * M + 1), vc(N * M + 1);
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      vr[mat[i][j]] = i;
      vc[mat[i][j]] = j;
    }

    int ans = 0;
    for (int e : arr) {
      int i = vr[e], j = vc[e];
      if (++rcnt[i] == M || ++ccnt[j] == N) return ans;
      ++ans;
    }
    return -1;
  }
};
