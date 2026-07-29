using ll = long long;

class Solution {
public:
  string smallestPalindrome(string s, int k) {
    int C[26]{}, D[26]{};
    for (char c : s) ++D[c - 'a'];
    for (int j = 0; j < 26; ++j) C[j] = D[j] / 2;

    auto get_total = [&]() {
      ll sum = 0, ret = 1, i = 0;
      for (int c = 0; c < 26; ++c) sum += C[c];
      for (int c = 0; c < 26; ++c) {
        for (int j = 0; j < C[c]; ++j) {
          ret *= ++i;
          ret /= j + 1;
          if (ret > k) return (ll)(k + 1);
        }
      }
      return ret;
    };
    if (get_total() < k) return "";

    string ans = ""; int N = s.size() / 2, tot = 0;
    for (int i = 0; i < N; ++i) {
      int c = 0;
      for (; c < 26; ++c) {
        if (C[c] == 0) continue;
        --C[c];
        int sub = get_total();
        if (tot + sub >= k) {
          ans += (char)(c + 'a');
          break;
        }
        tot += sub;
        ++C[c];
      }
    }

    string p = ans; reverse(p.begin(), p.end());
    for (int c = 0; c < 26; ++c) if (D[c] & 1) ans += (char)(c + 'a');
    return ans + p;
  }
};
