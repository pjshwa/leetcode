class Solution {
public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> ans;
    for (auto& word : words) {
      int p[26], v[26];
      memset(p, -1, sizeof(p));
      memset(v, -1, sizeof(v));

      int z = word.size(), f = 1;
      for (int i = 0; i < z; i++) {
        int from = word[i] - 'a', to = pattern[i] - 'a';
        if (p[from] != -1 && p[from] != to) f = 0;
        if (v[to] != -1 && v[to] != from) f = 0;
        if (!f) break;

        p[from] = to;
        v[to] = from;
      }

      if (f) ans.push_back(word);
    }

    return ans;
  }
};
