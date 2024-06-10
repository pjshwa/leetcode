class Solution {
public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    sort(arr1.begin(), arr1.end(), [&](int a, int b) {
      int i = find(arr2.begin(), arr2.end(), a) - arr2.begin();
      int j = find(arr2.begin(), arr2.end(), b) - arr2.begin();
      if (i == j) return a < b;
      return i < j;
    });
    return arr1;
  }
};
