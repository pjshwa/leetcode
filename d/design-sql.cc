class SQL {
  unordered_map<string, int> nameToTableId;
  vector<vector<vector<string>>> tables;
  vector<vector<bool>> removed;
  vector<int> columnCnts;

public:
  SQL(vector<string>& names, vector<int>& columns) {
    int N = names.size(); tables.resize(N);
    for (int i = 0; i < N; ++i) nameToTableId[names[i]] = i;
    this->columnCnts = columns;
  }

  bool ins(string name, vector<string> row) {
    if (!nameToTableId.count(name)) return false;

    int tableId = nameToTableId[name];
    if (row.size() != columnCnts[tableId]) return false;
    tables[tableId].push_back(row);
    removed[tableId].push_back(false);
    return true;
  }

  void rmv(string name, int rowId) {
    if (!nameToTableId.count(name)) return;

    --rowId;
    int tableId = nameToTableId[name];
    if (rowId < 0 || rowId >= tables[tableId].size()) return;
    removed[tableId][rowId] = true;
  }

  string sel(string name, int rowId, int columnId) {
    if (!nameToTableId.count(name)) return "<null>";

    --rowId, --columnId;
    int tableId = nameToTableId[name];
    if (rowId < 0 || rowId >= tables[tableId].size()) return "<null>";
    if (columnId < 0 || columnId >= columnCnts[tableId]) return "<null>";

    if (removed[tableId][rowId]) return "<null>";
    return tables[tableId][rowId][columnId];
  }

  vector<string> exp(string name) {
    if (!nameToTableId.count(name)) return {};

    int tableId = nameToTableId[name];
    vector<string> result;
    for (int i = 0; i < tables[tableId].size(); ++i) {
      if (removed[tableId][i]) continue;
      string row = "" + to_string(i + 1);
      for (auto& col : tables[tableId][i]) row += "," + col;
      result.push_back(row);
    }
    return result;
  }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * bool param_1 = obj->ins(name,row);
 * obj->rmv(name,rowId);
 * string param_3 = obj->sel(name,rowId,columnId);
 * vector<string> param_4 = obj->exp(name);
 */
