const int MAX = 2000, INF = 0x3f3f3f3f;

class Solution {
  int d[MAX + 1][MAX + 1], n, m;
  vector<int> arr1, arr2;

  int r(int i, int j) {
    if (d[i][j] != -1) return d[i][j];
    if (i == n - 1) return d[i][j] = 0;

    int ret = INF, v = j ? arr2[j - 1] : arr1[i];
    int nl = upper_bound(arr2.begin(), arr2.end(), v) - arr2.begin() + 1;

    for (int l : {0, nl}) {
      if (l > m) continue;
      int nv = l ? arr2[l - 1] : arr1[i + 1];
      if (nv > v) ret = min(ret, r(i + 1, l) + (l > 0));
    }
    return d[i][j] = ret;
  }

public:
  int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    sort(arr2.begin(), arr2.end());

    this->arr1 = arr1; this->arr2 = arr2;
    n = arr1.size(); m = arr2.size();
    memset(d, -1, sizeof(d));

    int res = INF;
    for (int l = 0; l <= m; l++) {
      int nv = l ? arr2[l - 1] : arr1[0];
      res = min(res, r(0, l) + (l > 0));
    }
    return res == INF ? -1 : res;
  }
};
