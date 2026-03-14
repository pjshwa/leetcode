class Solution {
public:
  string getHappyString(int n, int k) {
    int total = 3;
    for (int i = 1; i < n; ++i) total *= 2;
    if (--k >= total) return "";

    total /= 3;
    string ans = string(1, (k / total) + 'a');
    k %= total;

    string t = "abc";
    for (int i = 1; i < n; ++i) {
      string u = "";
      for (char c : t) {
        if (c != ans.back()) u.push_back(c);
      }
      total /= 2;
      ans += u[k / total];
      k %= total;
    }
    return ans;
  }
};
