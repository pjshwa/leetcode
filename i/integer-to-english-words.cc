class Solution {
  string D[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
  string T[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
  string S[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
                  "Nineteen"};
  
  string triple_to_str(int num) {
    string ret = "";
    if (num >= 100) {
      ret += " " + D[num / 100] + " Hundred";
      num %= 100;
    }
    if (num >= 10) {
      if (num >= 20) {
        ret += " " + T[num / 10];
        num %= 10;
      } else {
        ret += " " + S[num - 10];
        num = 0;
      }
    }
    if (num > 0) {
      ret += " " + D[num];
    }
    return ret.substr(1);
  }

public:
  string numberToWords(int num) {
    if (num == 0) return "Zero";

    string ret = "";
    if (num >= 1'000'000'000) {
      ret += " " + triple_to_str(num / 1'000'000'000) + " Billion";
      num %= 1'000'000'000;
    }
    if (num >= 1'000'000) {
      ret += " " + triple_to_str(num / 1'000'000) + " Million";
      num %= 1'000'000;
    }
    if (num >= 1'000) {
      ret += " " + triple_to_str(num / 1'000) + " Thousand";
      num %= 1'000;
    }
    if (num > 0) {
      ret += " " + triple_to_str(num);
    }
    return ret.substr(1);
  }
};
