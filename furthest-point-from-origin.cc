class Solution {
public:
  int furthestDistanceFromOrigin(string moves) {
    int d = 0, v = 0;
    for (char m : moves) {
      if (m == 'L') d--;
      else if (m == 'R') d++;
      else v++;
    }
    return abs(d) + v;
  }
};
