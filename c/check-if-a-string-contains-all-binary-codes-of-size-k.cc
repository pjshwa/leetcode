class Solution {
public:
  bool hasAllCodes(string s, int k) {
    int n = s.size();
    if (n < k) return false;

    set<int> u;
    int cur = 0;
    for (int i = 0; i < k; i++) cur = cur * 2 + (s[i] - '0');
    u.insert(cur);

    for (int i = k; i < n; i++) {
      if (s[i - k] == '1') cur -= 1 << (k - 1);
      cur = cur * 2 + (s[i] - '0');
      u.insert(cur);
    }

    return u.size() == (1 << k);
  }
};
