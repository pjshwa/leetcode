class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    vector<pair<int, int>> F; int N = arr.size();
    for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) F.push_back({arr[i], arr[j]});
    sort(F.begin(), F.end(), [&](pair<int, int>& a, pair<int, int>& b) {
      return a.first * b.second < a.second * b.first;
    });
    return {F[k - 1].first, F[k - 1].second};
  }
};
