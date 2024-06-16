class Solution {
public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [] (const vector<int>& a, const vector<int>& b) {
      return a[1] > b[1];
    });

    int ans = 0;
    for (auto& v : boxTypes) {
      int x = v[0], u = v[1];
      int d = min(x, truckSize);
      ans += d * u;
      truckSize -= d;
    }

    return ans;
  }
};
