class Solution {
  int scores[100];
public:
  int scoreOfParentheses(string s) {
    memset(scores, 0, sizeof(scores));

    int level = 0;
    char last = '(';
    for (char& c : s) {
      if (c == '(') level++;
      else {
        if (last == '(') scores[--level] += 1;
        else {
          scores[level - 1] += 2 * scores[level];
          scores[level] = 0;
          level--;
        }
      }
      last = c;
    }
    return scores[0];
  }
};
