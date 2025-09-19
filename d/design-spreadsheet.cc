class Spreadsheet {
  vector<vector<int>> sheet;

  pair<int, int> getPosition(string cell) {
    int row = stoi(cell.substr(1)) - 1;
    int col = cell[0] - 'A';
    return {row, col};
  }

  int getCellValue(string cell) {
    auto [row, col] = getPosition(cell);
    return sheet[row][col];
  }

public:
  Spreadsheet(int rows) {
    sheet.resize(rows, vector<int>(26, 0));
  }

  void setCell(string cell, int value) {
    auto [row, col] = getPosition(cell);
    sheet[row][col] = value;
  }

  void resetCell(string cell) {
    auto [row, col] = getPosition(cell);
    sheet[row][col] = 0;
  }

  int getValue(string formula) {
    formula = formula.substr(1);
    stringstream ss(formula); string token;
    int sum = 0;
    while (getline(ss, token, '+')) {
      if (isalpha(token[0])) sum += getCellValue(token);
      else sum += stoi(token);
    }
    return sum;
  }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
