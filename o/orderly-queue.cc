class Solution {
public:
  string orderlyQueue(string s, int k) {
    if (k >= 2) {
      sort(s.begin(), s.end());
      return s;
    }
    else {
      string ans = s;
      for (int i = 0; i < s.size(); ++i) {
        string t = s.substr(i) + s.substr(0, i);
        if (t < ans) ans = t;
      }
      return ans;
    }
  }
};
