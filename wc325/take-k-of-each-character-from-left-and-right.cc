const int INF = 0x3f3f3f3f;

class Solution {
public:
  int takeCharacters(string s, int k) {
    if (k == 0) return 0;

    int n = s.size();
    vector<int> pa(n), pb(n), pc(n);
    pa[0] = s[0] == 'a';
    pb[0] = s[0] == 'b';
    pc[0] = s[0] == 'c';
    for (int i = 1; i < n; ++i) {
      pa[i] = pa[i - 1] + (s[i] == 'a');
      pb[i] = pb[i - 1] + (s[i] == 'b');
      pc[i] = pc[i - 1] + (s[i] == 'c');
    }

    int ac = 0, bc = 0, cc = 0, ans = INF;

    int left = 0, right = n;
    while (left < right) {
      int mid = (left + right) / 2;
      int a = pa[mid], b = pb[mid], c = pc[mid];
      if (a + ac >= k && b + bc >= k && c + cc >= k) right = mid;
      else left = mid + 1;
    }

    if (left < n) {
      int a = pa[left], b = pb[left], c = pc[left];
      if (a + ac >= k && b + bc >= k && c + cc >= k) {
        ans = min(ans, left + 1);
      }
    }

    for (int r = n - 1; r >= 0; r--) {
      ac += s[r] == 'a';
      bc += s[r] == 'b';
      cc += s[r] == 'c';

      if (ac >= k && bc >= k && cc >= k) {
        ans = min(ans, n - r);
        break;
      }

      int left = 0, right = r;
      while (left < right) {
        int mid = (left + right) / 2;
        int a = pa[mid], b = pb[mid], c = pc[mid];
        if (a + ac >= k && b + bc >= k && c + cc >= k) right = mid;
        else left = mid + 1;
      }

      if (left < r) {
        int a = pa[left], b = pb[left], c = pc[left];
        if (a + ac >= k && b + bc >= k && c + cc >= k) {
          ans = min(ans, n - r + left + 1);
        }
      }
    }

    return ans == INF ? -1 : ans;
  }
};
