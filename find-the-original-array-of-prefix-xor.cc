class Solution {
public:
  vector<int> findArray(vector<int>& pref) {
    int N = pref.size();

    vector<int> ans(N); ans[0] = pref[0];
    for (int i = 1; i < N; ++i) ans[i] = pref[i] ^ pref[i - 1];
    return ans;
  }
};
