using ll = long long;

class Solution {
public:
  string decodeAtIndex(string s, int k) {
    ll total = 0;
    for (auto c : s) {
      if (isdigit(c)) total *= c - '0';
      else ++total;
    }

    reverse(s.begin(), s.end());
    for (char c : s) {
      if (isdigit(c)) {
        total /= c - '0';
        k = (k - 1) % total + 1;
      }
      else {
        if (k == total) return string(1, c);
        --total;
      }
    }

    return "";
  }
};
