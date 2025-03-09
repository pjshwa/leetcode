class Solution {
public:
  int numberOfAlternatingGroups(vector<int>& colors, int k) {
    auto P = colors;
    for (int c : colors) P.push_back(c);

    int N = colors.size(), sum = 0;
    for (int i = 1; i < 2 * N; i += 2) P[i] ^= 1;
    for (int i = 0; i < k; ++i) sum += P[i];

    int ans = sum % k == 0;
    for (int i = k; i < k + N - 1; ++i) {
      sum += P[i] - P[i - k];
      ans += sum % k == 0;
    }
    return ans;
  }
};
