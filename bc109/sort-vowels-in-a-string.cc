class Solution {
  bool is_consonant(char c) {
    if ('a' <= c && c <= 'z') {
      return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
    }
    else {
      return c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U';
    }
  }

public:
  string sortVowels(string s) {
    vector<int> P;
    vector<char> C;

    int N = s.size();
    for (int i = 0; i < N; i++) {
      if (is_consonant(s[i])) continue;

      P.push_back(i);
      C.push_back(s[i]);
    }

    sort(C.begin(), C.end());
    string t = s;
    for (int i = 0; i < P.size(); i++) {
      t[P[i]] = C[i];
    }
    return t;
  }
};
