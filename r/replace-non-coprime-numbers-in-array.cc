class Solution {
public:
  vector<int> replaceNonCoprimes(vector<int>& nums) {
    vector<int> s;
    for (int e : nums) {
      while (!s.empty() && gcd(s.back(), e) > 1) {
        int g = gcd(s.back(), e);
        e = s.back() / g * e;
        s.pop_back();
      }
      s.push_back(e);
    }
    return s;
  }
};
