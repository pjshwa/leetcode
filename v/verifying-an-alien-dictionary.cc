class Solution {
public:
  bool isAlienSorted(vector<string>& words, string order) {
    int L[26][26]{};
    for (int i = 0; i < 26; i++) for (int j = i + 1; j < 26; j++) {
      L[order[i] - 'a'][order[j] - 'a'] = 1;
    }

    function<bool(string, string)> cmp = [&](string a, string b) {
      int i = 0, j = 0;
      while (i < a.size() && j < b.size()) {
        if (L[a[i] - 'a'][b[j] - 'a']) return true;
        if (L[b[j] - 'a'][a[i] - 'a']) return false;
        i++, j++;
      }
      return i == a.size();
    };

    int n = words.size();
    for (int i = 1; i < n; i++) if (!cmp(words[i - 1], words[i])) return false;
    return true;
  }
};
