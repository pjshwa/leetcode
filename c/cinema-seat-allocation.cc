class Solution {
public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    int ans = 0, l = 1; map<int, int> m;
    for (auto& seat : reservedSeats) {
      m[seat[0]] |= 1 << (seat[1] - 1);
    }
    for (auto& [k, v] : m) {
      if (k != l) {
        ans += 2 * (k - l);
        l = k;
      }
      int w1 = (v & 0b0111100000) == 0;
      int w2 = (v & 0b0000011110) == 0;
      int w3 = (v & 0b0001111000) == 0;
      if (w1 && w2) ans += 2;
      else if (w1 || w2 || w3) ans += 1;
      ++l;
    }
    ans += 2 * (n - l + 1);
    return ans;
  }
};
