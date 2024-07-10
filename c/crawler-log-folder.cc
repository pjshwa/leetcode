class Solution {
public:
  int minOperations(vector<string>& logs) {
    int ans = 0;
    for (auto& l : logs) {
      if (l == "../") ans = max(0, ans - 1);
      else if (l != "./") ++ans;
    }
    return ans;
  }
};
