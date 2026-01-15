class Solution {
public:
  int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
    int hl = -1, vl = -1, hStr = 0, vStr = 0, hMaxStr = 0, vMaxStr = 0;
    sort(hBars.begin(), hBars.end());
    for (int h : hBars) {
      if (h == hl + 1) ++hStr;
      else hStr = 1;
      hMaxStr = max(hMaxStr, hStr);
      hl = h;
    }
    sort(vBars.begin(), vBars.end());
    for (int v : vBars) {
      if (v == vl + 1) ++vStr;
      else vStr = 1;
      vMaxStr = max(vMaxStr, vStr);
      vl = v;
    }
    int side = min(hMaxStr, vMaxStr) + 1;
    return side * side;
  }
};
