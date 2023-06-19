class Solution {
public:
  int largestAltitude(vector<int>& gain) {
    int acc = 0, ans = 0;
    for (int e : gain) acc += e, ans = max(ans, acc);
    return ans;
  }
};
