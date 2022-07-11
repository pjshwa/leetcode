class Solution {
  int d[1001];
public:
  int longestStrChain(vector<string>& words) {
    int n = words.size();
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
      return a.size() < b.size();
    });

    for (int i = 0; i < n; i++) {
      d[i] = 1;

      for (int j = 0; j < i; j++) {
        if (words[j].size() + 1 != words[i].size()) continue;

        for (int k = 0; k < words[i].size(); k++) {
          string newword = words[i].substr(0, k) + words[i].substr(k + 1);
          if (words[j] == newword) d[i] = max(d[i], d[j] + 1);
        }
      }
    }

    return *max_element(d, d + n);
  }
};
