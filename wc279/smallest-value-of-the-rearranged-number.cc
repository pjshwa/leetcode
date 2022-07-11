class Solution {
public:
  long long smallestNumber(long long num) {
    if (num == 0) return 0;

    bool neg = num < 0;
    num = abs(num);

    if (neg) {
      string s = to_string(num);
      sort(s.begin(), s.end());
      reverse(s.begin(), s.end());
      return stoll('-' + s);
    }
    else {
      string s = to_string(num);
      sort(s.begin(), s.end());

      int i = 0;
      while (i < s.size() && s[i] == '0') i++;
      swap(s[0], s[i]);
      return stoll(s);
    }
      
  }
};
