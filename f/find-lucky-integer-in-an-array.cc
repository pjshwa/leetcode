const int MAXN = 500;

class Solution {
public:
  int findLucky(vector<int>& arr) {
    int T[MAXN + 1]{};
    for (int e : arr) ++T[e];
    for (int c = MAXN; c >= 1; --c) if (T[c] == c) return c;
    return -1;
  }
};
