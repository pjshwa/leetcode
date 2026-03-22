class Solution {
  void rotate(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<vector<int>> rotated(n, vector<int>(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
      rotated[j][n - 1 - i] = mat[i][j];
    }
    mat = rotated;
  }

public:
  bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    rotate(mat); if (mat == target) return true;
    rotate(mat); if (mat == target) return true;
    rotate(mat); if (mat == target) return true;
    rotate(mat); if (mat == target) return true;
    return false;
  }
};
