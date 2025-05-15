class Solution {
public:
  vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
    int N = words.size(), last = -1;
    vector<string> result;
    for (int i = 0; i < N; ++i) {
      if (groups[i] != last) {
        result.push_back(words[i]);
        last = groups[i];
      }
    }
    return result;
  }
};
