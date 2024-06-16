class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    result.push_back({1});

    for (int i = 1; i < numRows; ++i) {
      vector<int> row;
      for (int j = 0; j <= i; ++j) {
        if (j == 0 || j == i) row.push_back(1);
        else {
          auto& prev_row = result[i - 1];
          row.push_back(prev_row[j - 1] + prev_row[j]);
        }
      }
      result.push_back(row);
    }

    return result;
  }
};
