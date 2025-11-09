class Solution {
public:
  int countOperations(int num1, int num2) {
    for (int t = 0;; ++t) {
      if (num1 == 0 || num2 == 0) return t;
      if (num1 >= num2) num1 -= num2;
      else num2 -= num1;
    }
    return -1;
  }
};
