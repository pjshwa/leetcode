class Solution {
public:
  long long makeSubKSumEqual(vector<int>& arr, int k) {
    int n = arr.size(); k = __gcd(k, n);
    vector<int> T[k];

    for (int i = 0; i < n; i++) {
      T[i % k].push_back(arr[i]);
    }

    long long ans = 0;
    for (int i = 0; i < k; i++) {
      sort(T[i].begin(), T[i].end());

      int z = T[i].size(), m = T[i][z / 2];
      for (int j = 0; j < z; j++) {
        ans += abs(T[i][j] - m);
      }
    }
    return ans;
  }
};
