class Solution {
public:
  bool checkPowersOfThree(int n) {
    int pw = 1;
    for (int t = 0; t < 15; ++t) pw *= 3;

    while (pw) {
      if (n >= pw) n -= pw;
      pw /= 3;
    }
    return n == 0;
  }
};
