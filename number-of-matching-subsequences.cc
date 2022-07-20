class Solution {
  vector<int> p[26];
public:
  int numMatchingSubseq(string s, vector<string>& words) {
    for (int i = 0; i < s.size(); i++) {
      p[s[i] - 'a'].push_back(i);
    }

    int ans = 0;
    for (auto& word : words) {
      int z = word.size(), last = -1;
      bool able = true;
      for (int i = 0; i < z; i++) {
        int c = word[i] - 'a';
        auto it = upper_bound(p[c].begin(), p[c].end(), last);
        if (it == p[c].end()) {
          able = false;
          break;
        }
        last = *it;
      }
      if (able) ans++;
    }

    return ans;
  }
};
