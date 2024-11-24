using ll = long long;

class Solution {
public:
  ll maxMatrixSum(vector<vector<int>>& matrix) {
    vector<int> values; ll sum = 0;
    for (auto& row : matrix) for (int x : row) {
      sum += x;
      values.push_back(x);
    }
    sort(values.begin(), values.end());

    for (int i = 0; i + 1 < values.size(); i += 2) {
      int cur = values[i] + values[i + 1];
      if (cur < 0) sum -= 2 * cur;
      else break;
    }
    return sum;
  }
};
