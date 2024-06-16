class Solution {
public:
  int findSpecialInteger(vector<int>& arr) {
    int N = arr.size(), L = N / 4;

    int streak = 0;
    for (int i = 0; i < N; ++i) {
      if (i > 0 && arr[i] == arr[i - 1]) {
        ++streak;
        if (streak > L) return arr[i];
      }
      else streak = 1;
    }

    return arr[0];
  }
};
