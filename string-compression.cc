class Solution {
public:
  int compress(vector<char>& chars) {
    int n = chars.size(), l = 0;
    char lchar = chars[0]; int streak = 1;

    auto add = [&](char c, int n) {
      chars[l++] = c;
      if (n > 1) {
        string s = to_string(n);
        for (char c : s) chars[l++] = c;
      }
    };

    for (int i = 1; i < n; i++) {
      if (lchar == chars[i]) streak++;
      else {
        add(lchar, streak);
        lchar = chars[i];
        streak = 1;
      }
    }
    add(lchar, streak);
    return l;
  }
};
