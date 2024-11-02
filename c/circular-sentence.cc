class Solution {
public:
  bool isCircularSentence(string sentence) {
    int N = sentence.size();
    for (int i = 0; i < N; ++i) {
      if (sentence[i] != ' ') continue;
      if (sentence[i - 1] != sentence[i + 1]) return false;
    }
    return sentence[0] == sentence[N - 1];
  }
};
