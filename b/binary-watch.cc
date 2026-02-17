class Solution {
public:
  vector<string> readBinaryWatch(int turnedOn) {
    int H[4] = {1, 2, 4, 8}, M[6] = {1, 2, 4, 8, 16, 32};
    vector<string> res;
    for (int s = 0; s < (1 << 10); ++s) {
      if (__builtin_popcount(s) != turnedOn) continue;
      int h = 0, m = 0;
      for (int i = 0; i < 4; ++i) if (s & (1 << i)) h += H[i];
      for (int i = 0; i < 6; ++i) if (s & (1 << (i + 4))) m += M[i];
      if (h >= 12 || m >= 60) continue;
      res.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
    }
    return res;
  }
};
