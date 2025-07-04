class Solution {
public:
  int countOddLetters(int n) {
    string W[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int T[26]{};
    while (n) {
      int d = n % 10; n /= 10;
      for (char c : W[d]) T[c - 'a'] ^= 1;
    }
    return accumulate(T, T + 26, 0);
  }
};
