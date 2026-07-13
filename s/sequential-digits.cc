class Solution {
public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> ans;
    for (int d = 1; d <= 9; ++d) {
      int num = 0;
      for (int j = d; j <= 9; ++j) {
        num = num * 10 + j;
        if (num > high) break;
        if (num >= low) ans.push_back(num);
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};
