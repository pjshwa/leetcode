class Solution {
public:
  bool threeConsecutiveOdds(vector<int>& arr) {
    int N = arr.size();
    for (int i = 2; i < N; ++i) {
      int v1 = arr[i - 2], v2 = arr[i - 1], v3 = arr[i];
      if (v1 % 2 == 1 && v2 % 2 == 1 && v3 % 2 == 1) {
        return true;
      }
    }
    return false;
  }
};
