class Solution {
  int d[205][205];
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    d[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        if (j == 0) d[i][j] = d[i - 1][j] + triangle[i][j];
        else if (i == j) d[i][j] = d[i - 1][j - 1] + triangle[i][j];
        else d[i][j] = min(d[i - 1][j - 1], d[i - 1][j]) + triangle[i][j];
      }
    }
    return *min_element(d[n - 1], d[n - 1] + n);
  }
};
