class Solution {
public:
  string answerString(string word, int numFriends) {
    if (numFriends == 1) return word;

    int N = word.size(), sz = N - numFriends + 1;
    string ans = word.substr(0, sz);
    for (int i = 1; i < N; ++i) {
      ans = max(ans, word.substr(i, sz));
    }
    return ans;
  }
};
