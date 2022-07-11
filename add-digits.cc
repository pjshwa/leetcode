class Solution {
public:
  int addDigits(int num) {
    // if (num < 10) return num;

    // string s = to_string(num);
    // int nxt = 0;
    // for (char& c : s) nxt += c - '0';
    // return addDigits(nxt);
    if (num == 0) return 0;
    return (num - 1) % 9 + 1;
  }
};
