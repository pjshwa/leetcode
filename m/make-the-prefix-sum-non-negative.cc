class Solution {
public:
  int makePrefSumNonNegative(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> negs;
    long long sum = 0; int ans = 0;
    for (int e : nums) {
      if (e < 0) negs.push(e);
      sum += e;
      if (sum < 0) {
        sum -= negs.top(); negs.pop();
        ++ans;
      }
    }
    return ans;
  }
};
