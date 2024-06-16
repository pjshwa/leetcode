using ll = long long;

class Solution {
public:
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    vector<pair<int, int>> V; int N = dist.size();
    for (int i = 0; i < N; ++i) V.push_back({dist[i], speed[i]});
    sort(V.begin(), V.end(), [](auto& a, auto& b) {
      auto [d1, s1] = a; auto [d2, s2] = b;
      return (ll)d1 * s2 < (ll)d2 * s1;
    });

    for (int i = 0; i < N; ++i) {
      auto [d, s] = V[i];
      if ((ll)i * s >= d) return i;
    }
    return N;
  }
};
