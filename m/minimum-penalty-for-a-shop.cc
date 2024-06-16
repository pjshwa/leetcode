class Solution {
public:
  int bestClosingTime(string customers) {
    int N = customers.size(), total_yc = 0;
    for (int i = 0; i < N; i++) total_yc += customers[i] == 'Y';

    int pen = N - total_yc, ans = N, right_yc = 0;
    for (int i = N - 1; i >= 0; i--) {
      bool is_y = customers[i] == 'Y';
      if (is_y) total_yc -= 1, right_yc += 1;

      int npen = i - total_yc + right_yc;
      if (npen <= pen) pen = npen, ans = i;
    }

    return ans;
  }
};
