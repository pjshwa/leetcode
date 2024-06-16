using ll = long long;

class Solution {
public:
  string kthLuckyNumber(int k) {
    ll t = 1;
    while (k > (2LL << t) - 2) ++t;

    k -= (1LL << t) - 2; --k;
    
    // convert k to binary
    string s;
    while (k) {
      s += (k & 1) ? '7' : '4';
      k >>= 1;
    }
    while (s.size() < t) s.push_back('4');
    reverse(s.begin(), s.end());
    return s;
  }
};
