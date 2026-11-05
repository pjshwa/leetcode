class Solution {
public:
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int ans = 0;
    for (int e : arr1) {
      int ok = 1;
      for (int f : arr2) ok &= abs(e - f) > d;
      ans += ok;
    }
    return ans;
  }
};
