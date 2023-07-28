class Solution {
public:
  bool isItPossible(string word1, string word2) {
    int ta[26]{}, tb[26]{};
    for (char& c : word1) ta[c - 'a']++;
    for (char& c : word2) tb[c - 'a']++;

    for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) {
      if (ta[i] == 0 || tb[j] == 0) continue;

      ta[i]--; ta[j]++;
      tb[j]--; tb[i]++;

      int da = 0, db = 0;
      for (int k = 0; k < 26; k++) {
        if (ta[k] > 0) da++;
        if (tb[k] > 0) db++;
      }
      if (da == db) return true;

      ta[i]++; ta[j]--;
      tb[j]++; tb[i]--;
    }

    return false;
  }
};
