class Solution {
public:
  string addBinary(string a, string b) {
    int az = a.size(), bz = b.size();

    int carry = 0; string ans = "";
    for (int i = 0; i < max(az, bz); i++) {
      int ai, bi;
      if (a.empty()) ai = 0;
      else ai = a.back() - '0', a.pop_back();
      if (b.empty()) bi = 0;
      else bi = b.back() - '0', b.pop_back();

      int sum = ai + bi + carry;
      carry = sum / 2;
      ans += (sum % 2) + '0';
    }
    if (carry) ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
