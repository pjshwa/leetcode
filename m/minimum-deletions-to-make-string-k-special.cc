class Solution {
public:
  int minimumDeletions(string word, int k) {
    int N = word.size();
    vector<int> freq(26, 0);
    for (char c : word) ++freq[c - 'a'];

    int ans = N;
    for (int lb = 1; lb <= N; ++lb) {
      int ub = lb + k, cnt = 0;
      for (int c = 0; c < 26; ++c) {
        if (freq[c] < lb) cnt += freq[c];
        else if (freq[c] > ub) cnt += freq[c] - ub;
      }
      if (cnt < ans) ans = cnt;
    }
    return ans;
  }
};
