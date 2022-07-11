class Solution {
public:
  int myAtoi(string s) {
    int i = 0, n = s.size();

    // 1. Read in and ignore any leading whitespace.
    while (i < n && s[i] == ' ') i++;

    // 2. Check if the next character (if not already at the end of the string) is '-' or '+'.
    // Read this character in if it is either.
    // This determines if the final result is negative or positive respectively.
    // Assume the result is positive if neither is present.
    if (i == n) return 0;
    bool neg = false;
    if (s[i] == '-' || s[i] == '+') {
      neg = (s[i] == '-');
      i++;
    }

    // 3. Read in next the characters until the next non-digit character or the end of the input is reached.
    // The rest of the string is ignored.
    // 4. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32).
    // If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
    // 5. If the integer is out of the 32-bit signed integer range [-231, 231 - 1],
    // then clamp the integer so that it remains in the range.
    // Specifically, integers less than -231 should be clamped to -231,
    // and integers greater than 231 - 1 should be clamped to 231 - 1.
    long long plim = (1LL << 31);
    long long res = 0;
    while (i < n && s[i] >= '0' && s[i] <= '9') {
      res = res * 10 + (s[i] - '0');
      if (res > plim) res = plim;
      i++;
    }

    if (neg) res = -res;
    if (res == plim) res--;
    return res;
  }
};
