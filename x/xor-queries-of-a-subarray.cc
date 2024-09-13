class Solution {
public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int N = arr.size();
    int P[N + 1]; P[0] = 0;
    for (int i = 1; i <= N; ++i) P[i] = P[i - 1] ^ arr[i - 1];

    vector<int> ans;
    for (auto& Q : queries) {
      int l = Q[0], r = Q[1];
      ans.push_back(P[r + 1] ^ P[l]);
    }
    return ans;
  }
};
