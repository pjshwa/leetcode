class Solution {
public:
  vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    int N = arr2.size(), M = arr3.size(), i = 0, j = 0;
    vector<int> res;
    for (int e : arr1) {
      while (i < N && arr2[i] < e) ++i;
      while (j < M && arr3[j] < e) ++j;
      if (i < N && j < M && arr2[i] == e && arr3[j] == e) res.push_back(e);
    }
    return res;
  }
};
