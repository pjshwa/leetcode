class Solution {
  bool contains(string& a, string& b) {
    if (a.size() < b.size()) return false;
    for (int i = 0; i + b.size() <= a.size(); ++i) {
      if (a.substr(i, b.size()) == b) return true;
    }
    return false;
  }

public:
  vector<string> stringMatching(vector<string>& words) {
    vector<string> ans;
    for (auto& word1 : words) {
      int ok = 0;
      for (auto& word2 : words) {
        if (word1 != word2 && contains(word2, word1)) {
          ok = 1;
          break;
        }
      }
      if (ok) ans.push_back(word1);
    }
    return ans;
  }
};
