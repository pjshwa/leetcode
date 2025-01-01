class Solution {
public:
  string stringShift(string s, vector<vector<int>>& shift) {
    int rot = 0, N = s.size();
    for (auto& sh : shift) {
      int v = sh[1] % N;
      rot = (rot + (sh[0] ? N - v : v)) % N;
    }
    rotate(s.begin(), s.begin() + rot, s.end());
    return s;
  }
};
