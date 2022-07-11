class Solution {
  bool si[10'000], sd[10'000];
public:
  bool validMountainArray(vector<int>& arr) {
    int n = arr.size();
    memset(si, 0, sizeof(si));
    memset(sd, 0, sizeof(sd));

    for (int i = 1; i < n; i++) {
      if (arr[i] > arr[i - 1]) si[i] = 1;
      else break;
    }

    for (int i = n - 2; i >= 0; i--) {
      if (arr[i] > arr[i + 1]) sd[i] = 1;
      else break;
    }

    for (int i = 0; i < n; i++) if (si[i] && sd[i]) return 1;
    return 0;
  }
};
