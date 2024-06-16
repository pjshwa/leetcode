class Solution {
public:
  int countTriplets(vector<int>& arr) {
    map<int, vector<int>> t;
    t[0].push_back(-1);

    int N = arr.size(), acc = 0;
    for (int i = 0; i < N; i++) {
      acc ^= arr[i];
      t[acc].push_back(i);
    }

    int ans = 0;
    for (auto& [_, v] : t) {
      int Z = v.size();
      for (int i = 0; i < Z; i++) for (int j = i + 1; j < Z; j++) {
        ans += v[j] - v[i] - 1;
      }
    }
    return ans;
  }
};
