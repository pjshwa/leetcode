class Solution {
public:
  bool isIsomorphic(string s, string t) {
    map<char, char> m1, m2; int N = s.size();
    for (int i = 0; i < N; ++i) {
      if (m1.count(s[i]) && m1[s[i]] != t[i]) return false;
      m1[s[i]] = t[i];

      if (m2.count(t[i]) && m2[t[i]] != s[i]) return false;
      m2[t[i]] = s[i];
    }

    string u = s;
    for (char& c : u) c = m1[c];
    return u == t;
  }
};
