class Solution {
public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    set<char> S(allowed.begin(), allowed.end()); int ans = 0;
    for (string& u : words) {
      int ok = 1;
      for (char& c : u) ok &= S.count(c);
      ans += ok;
    }
    return ans;
  }
};
