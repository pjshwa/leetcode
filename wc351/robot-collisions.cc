class Solution {
public:
  vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int N = positions.size();
    vector<tuple<int, int, int, int>> T;
    for (int i = 0; i < N; i++) {
      T.push_back({positions[i], healths[i], directions[i] == 'L' ? -1 : 1, i});
    }
    sort(T.begin(), T.end());

    vector<pair<int, int>> U, R;
    for (int i = 0; i < N; i++) {
      auto [p, h, d, j] = T[i];

      if (d == -1) {
        if (R.empty()) U.push_back({h, j});
        else {
          while (!R.empty() && h) {
            auto [oh, oj] = R.back();
            if (oh == h) {
              R.pop_back();
              h = 0;
              break;
            }
            else if (oh > h) {
              R.pop_back();
              R.push_back({oh - 1, oj});
              h = 0;
              break;
            }
            else {
              R.pop_back();
              h--;
            }
          }
          if (R.empty() && h) U.push_back({h, j});
        }
      }
      else R.push_back({h, j});
    }

    for (auto [h, j] : R) U.push_back({h, j});
    sort(U.begin(), U.end(), [](auto& a, auto& b) { return a.second < b.second; });

    vector<int> ans;
    for (auto [h, j] : U) ans.push_back(h);
    return ans;
  }
};
