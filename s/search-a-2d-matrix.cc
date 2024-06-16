class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();

    int left = 0, right = n * m - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      int x = mid / m, y = mid % m;
      if (matrix[x][y] < target) left = mid + 1;
      else right = mid;
    }

    int x = left / m, y = left % m;
    return matrix[x][y] == target;
  }
};
