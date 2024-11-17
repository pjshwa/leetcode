class Solution {
public:
  int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    int maxDiag = 0, maxArea = 0;
    for (auto& dim : dimensions) {
      int x = dim[0], y = dim[1];
      int diag = x * x + y * y;
      if (diag > maxDiag) {
        maxDiag = diag;
        maxArea = x * y;
      } else if (diag == maxDiag) {
        maxArea = max(maxArea, x * y);
      }
    }
    return maxArea;
  }
};
