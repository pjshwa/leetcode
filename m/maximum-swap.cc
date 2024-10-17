class Solution {
public:
  int maximumSwap(int num) {
    string ans = to_string(num); int N = ans.size();
    for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) {
      string U = to_string(num); swap(U[i], U[j]);
      if (U > ans) ans = U;
    }
    return stoi(ans);
  }
};
