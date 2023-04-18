class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    reverse(word1.begin(), word1.end());
    reverse(word2.begin(), word2.end());

    string ret = "";
    while (!word1.empty() || !word2.empty()) {
      if (!word1.empty()) {
        ret += word1.back();
        word1.pop_back();
      }
      if (!word2.empty()) {
        ret += word2.back();
        word2.pop_back();
      }
    }
    return ret;
  }
};
