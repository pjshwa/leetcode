class Solution {
  int d[1000][2];
public:
  int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    memset(d, 0, sizeof(d));

    d[0][0] = d[0][1] = 1;
    for (int i = 1; i < n; i++) for (int j = 0; j < i; j++) {
      if (nums[i] > nums[j]) d[i][0] = max(d[i][0], d[j][1] + 1);
      if (nums[i] < nums[j]) d[i][1] = max(d[i][1], d[j][0] + 1);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) ans = max({ans, d[i][0], d[i][1]});
    return ans;
  }
};
