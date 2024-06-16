class Solution {
public:
  int partitionString(string s) {
    map<char, int> t;
    int ans = 1;
    for (char c : s) {
      if (t.count(c)) t.clear(), ans++;
      t[c] = 1;
    }
    return ans;
  }
};
