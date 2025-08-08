class Solution {
public:
  int smallestCommonElement(vector<vector<int>>& mat) {
    for (int e : mat[0]) {
      int ok = 1;
      for (auto& row : mat) {
        if (!binary_search(row.begin(), row.end(), e)) {
          ok = 0;
          break;
        }
      }
      if (ok) return e;
    }
    return -1;
  }
};
