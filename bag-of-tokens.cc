class Solution {
public:
  int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());
    int n = tokens.size();

    if (n == 0 || power < tokens[0]) return 0;

    int lp = 0, acc = 0, pow = power, cur = 0;
    while (lp < n && acc + tokens[lp] <= pow) {
      acc += tokens[lp++];
      cur++;
    }

    int ans = cur;
    for (int rp = n - 1; rp > lp; rp--) {
      pow += tokens[rp];
      cur--;

      while (lp < rp && acc + tokens[lp] <= pow) {
        acc += tokens[lp++];
        cur++;
      }

      ans = max(ans, cur);
    }

    return ans;
  }
};
