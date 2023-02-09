class Solution {
public:
  long long distinctNames(vector<string>& ideas) {
    int E[26][26]{};

    unordered_set<string> S;
    for (auto& s : ideas) S.insert(s);
    for (auto& s : S) {
      int f = s[0] - 'a';
      for (int p = 0; p < 26; p++) {
        string t = s; t[0] = p + 'a';
        if (!S.count(t)) E[f][p]++;
      }
    }

    long long ans = 0;
    for (auto& s : S) {
      int f = s[0] - 'a';
      for (int p = 0; p < 26; p++) {
        string t = s; t[0] = p + 'a';
        if (!S.count(t)) ans += E[p][f];
      }
    }

    return ans;
  }
};
