class Solution {
public:
  int maxLength(vector<string>& arr) {
    int N = arr.size(), ans = 0, B[26]{};
    for (int s = 0; s < (1 << N); ++s) {
      for (int i = 0; i < N; ++i) {
        if (!(s & (1 << i))) continue;
        for (char& c : arr[i]) ++B[c - 'a'];
      }

      int cur = 0, ok = 1;
      for (int l = 0; l < 26; ++l) {
        if (B[l] > 1) ok = 0;
        else cur += B[l];
      }
      if (ok) ans = max(ans, cur);

      for (int i = 0; i < N; ++i) {
        if (!(s & (1 << i))) continue;
        for (char& c : arr[i]) --B[c - 'a'];
      }
    }

    return ans;
  }
};
