class Solution {
public:
  int countLargestGroup(int n) {
    vector<int> C(40, 0);
    for (int i = 1; i <= n; ++i) {
      int num = i, sum = 0;
      while (num) sum += num % 10, num /= 10;
      ++C[sum];
    }
    int maxc = *max_element(C.begin(), C.end()), ans = 0;
    for (int e : C) ans += e == maxc;
    return ans;
  }
};
