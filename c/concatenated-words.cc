class Solution {
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
      return a.size() < b.size();
    });

    set<string> pre; vector<string> ans;
    for (auto& word : words) {
      int n = word.size();
      bool d[n + 1]; fill(d, d + n + 1, false); d[0] = true;
      for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
          if (d[j] && pre.count(word.substr(j, i - j))) {
            d[i] = true;
            break;
          }
        }
      }
      if (d[n]) ans.push_back(word);
      pre.insert(word);
    }

    return ans;
  }
};
