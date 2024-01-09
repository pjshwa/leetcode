/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
  int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
    auto dimensions = binaryMatrix.dimensions();
    int rows = dimensions[0], cols = dimensions[1];

    int ans = cols;
    for (int row = 0; row < rows; ++row) {
      int l = 0, r = cols;
      while (l < r) {
        int m = (l + r) / 2;
        if (binaryMatrix.get(row, m) == 0) l = m + 1;
        else r = m;
      }
      ans = min(ans, l);
    }
    if (ans == cols) ans = -1;
    return ans;
  }
};

