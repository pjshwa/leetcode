class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> prev{1};
    for (int i = 1; i < rowIndex; i++) {
      vector<int> row(i + 1, 1);
      for (int j = 1; j < i; j++) row[j] = prev[i - 1][j - 1] + prev[i - 1][j];
      prev = row;
    }
    return prev;
  }
};
