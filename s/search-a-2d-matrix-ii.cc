class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int ni = 0, mi = m - 1;
    while (1) {
      if (ni >= n || mi < 0) return false;
      if (matrix[ni][mi] == target) return true;
      if (matrix[ni][mi] > target) mi--;
      else ni++;
    }
    return false;
  }
};
