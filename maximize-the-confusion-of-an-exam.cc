class Solution {
public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    int N = answerKey.size(), ans = 0, r = 0, fc = 0, tc = 0;
    for (int l = 0; l < N; l++) {
      while (r < N) {
        if (answerKey[r] == 'T') {
          if (min(tc + 1, fc) > k) break;
          else r++, tc++;
        }
        else {
          if (min(fc + 1, tc) > k) break;
          else r++, fc++;
        }
      }

      ans = max(ans, r - l);
      if (answerKey[l] == 'T') tc--;
      else fc--;
    }
    return ans;
  }
};
