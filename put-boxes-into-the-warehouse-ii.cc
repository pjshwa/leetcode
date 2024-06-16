class Solution {
public:
  int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
    int N = warehouse.size(), M = boxes.size(), ans = 0;

    vector<int> pheight_l(N, INT_MAX), pheight_r(N, INT_MAX);
    for (int i = 0; i < N; ++i) {
      pheight_l[i] = i == 0 ? warehouse[i] : min(pheight_l[i - 1], warehouse[i]);
    }
    for (int i = N - 1; i >= 0; --i) {
      pheight_r[i] = i == N - 1 ? warehouse[i] : min(pheight_r[i + 1], warehouse[i]);
    }
    for (int i = 0; i < N; ++i) {
      warehouse[i] = min(warehouse[i], max(pheight_l[i], pheight_r[i]));
    }

    sort(warehouse.begin(), warehouse.end(), greater<int>());
    sort(boxes.begin(), boxes.end(), greater<int>());

    int j = 0, ans = 0;
    for (int i = 0; i < N; ++i) {
      while (j < M && boxes[j] > warehouse[i]) ++j;
      if (j < M) ++ans, ++j;
    }
    return ans;
  }
};
