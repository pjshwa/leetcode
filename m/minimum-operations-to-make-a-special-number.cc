class Solution {
public:
  int minimumOperations(string num) {
    int N = num.size();

    int ans = N;
    for (char c : num) if (c == '0') ans = N - 1;

    for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++) {
      if (
        (num[i] == '0' && num[j] == '0') ||
        (num[i] == '2' && num[j] == '5') ||
        (num[i] == '5' && num[j] == '0') ||
        (num[i] == '7' && num[j] == '5')
      ) {
        ans = min(ans, N - i - 2);
      }
    }

    return ans;
  }
};
