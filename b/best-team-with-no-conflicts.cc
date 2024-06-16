using pii = pair<int, int>;

class Solution {
public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    int N = scores.size();

    vector<pii> v;
    for (int i = 0; i < N; i++) v.push_back({ages[i], scores[i]});
    sort(v.begin(), v.end());

    int d[N], ans = 0;
    fill(d, d + N, 0);
    for (int i = 0; i < N; i++) {
      d[i] = v[i].second;
      for (int j = i - 1; j >= 0; j--) {
        if (v[i].second >= v[j].second) d[i] = max(d[i], d[j] + v[i].second);
      }
      ans = max(ans, d[i]);
    }
    return ans;
  }
};
