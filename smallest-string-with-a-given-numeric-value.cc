class Solution {
public:
  string getSmallestString(int n, int k) {
    int a[n];
    for (int i = 0; i < n; i++) a[i] = 1;

    int i = n - 1;
    k -= n;
    while (k) {
      int sub = min(25, k);
      k -= sub;
      a[i--] += sub;
    }

    string ans = "";
    for (int i = 0; i < n; i++) {
      ans += 'a' + a[i] - 1;
    }

    return ans;
      
  }
};
