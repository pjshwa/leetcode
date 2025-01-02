class Solution {
  bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

public:
  vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    int N = words.size();
    vector<int> P(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
      auto word = words[i - 1];
      int ok = is_vowel(word[0]) && is_vowel(word.back());
      P[i] = P[i - 1] + ok;
    }

    vector<int> ans;
    for (auto& q : queries) {
      int l = q[0], r = q[1];
      ans.push_back(P[r + 1] - P[l]);
    }
    return ans;
  }
};
