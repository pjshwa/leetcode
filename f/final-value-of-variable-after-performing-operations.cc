class Solution {
public:
  int finalValueAfterOperations(vector<string>& operations) {
    int x = 0;
    for (auto& op : operations) {
      char t = op[0] == 'X' ? op[2] : op[0];
      t == '+' ? ++x : --x;
    }
    return x;
  }
};
