class Solution {
public:
  vector<int> decrypt(vector<int>& code, int k) {
    int N = code.size();
    vector<int> res(N, 0);
    if (k == 0) return res;

    if (k > 0) {
      for (int i = 1; i <= k; ++i) res[0] += code[i];
      for (int i = 1; i < N; ++i) {
        res[i] = res[i - 1] - code[i] + code[(i + k) % N];
      }
    } else {
      for (int i = -1; i >= k; --i) res[0] += code[N + i];
      for (int i = 1; i < N; ++i) {
        res[i] = res[i - 1] + code[i - 1] - code[(i + k - 1 + N) % N];
      }
    }

    return res;
  }
};
