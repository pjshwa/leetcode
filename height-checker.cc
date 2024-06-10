class Solution {
public:
  int heightChecker(vector<int>& heights) {
    vector<int> sorted(heights);
    sort(sorted.begin(), sorted.end());

    int ans = 0;
    for (int i = 0; i < heights.size(); ++i) ans += heights[i] != sorted[i];
    return ans;
  }
};
