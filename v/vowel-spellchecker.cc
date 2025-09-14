class Solution {
  bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

public:
  vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    vector<string> res;
    map<string, string> S1, S2, S3;
  
    reverse(wordlist.begin(), wordlist.end());
    for (auto w : wordlist) {
      S1[w] = w;

      string w_lower = w;
      transform(w_lower.begin(), w_lower.end(), w_lower.begin(), ::tolower);
      S2[w_lower] = w;

      for (auto& c : w_lower) if (is_vowel(c)) c = '*';
      S3[w_lower] = w;
    }

    for (auto q : queries) {
      if (S1.count(q)) {
        res.push_back(S1[q]);
        continue;
      }

      string q_lower = q;
      transform(q_lower.begin(), q_lower.end(), q_lower.begin(), ::tolower);
      if (S2.count(q_lower)) {
        res.push_back(S2[q_lower]);
        continue;
      }

      for (auto& c : q_lower) if (is_vowel(c)) c = '*';
      if (S3.count(q_lower)) {
        res.push_back(S3[q_lower]);
        continue;
      }

      res.push_back("");
    }

    return res;
  }
};
