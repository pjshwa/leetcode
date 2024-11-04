class Solution {
public:
  string compressedString(string word) {
    vector<pair<char, int>> compressed;
    int last = 0, streak = 0;
    for (char c : word) {
      if (c == last && streak < 9) ++streak;
      else {
        if (streak) compressed.push_back({last, streak});
        last = c; streak = 1;
      }
    }
    if (streak) compressed.push_back({last, streak});

    string res = "";
    for (auto [c, n] : compressed) {
      res += to_string(n) + c;
    }
    return res;
  }
};
