class Solution {
public:
  long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
    long long N = bottomLeft.size(), ans = 0;
    for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) {
      int x1 = bottomLeft[i][0], y1 = bottomLeft[i][1];
      int x2 = topRight[i][0], y2 = topRight[i][1];

      // calculate overlapping rectangle
      int ox1 = max(x1, bottomLeft[j][0]), oy1 = max(y1, bottomLeft[j][1]);
      int ox2 = min(x2, topRight[j][0]), oy2 = min(y2, topRight[j][1]);
      if (ox1 < ox2 && oy1 < oy2) {
        long long side = min(ox2 - ox1, oy2 - oy1);
        ans = max(ans, side * side);
      }
    }
    return ans;
  }
};
