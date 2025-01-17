class Solution {
public:
  bool doesValidArrayExist(vector<int>& derived) {
    int N = derived.size();
    vector<int> ans(N, 0);
    for (int i = 1; i < N; ++i) ans[i] = ans[i - 1] ^ derived[i - 1];
    return ans[0] == (ans[N - 1] ^ derived[N - 1]);
  }
};
