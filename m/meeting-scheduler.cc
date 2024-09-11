class Solution {
public:
  vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
    int N = slots1.size(), M = slots2.size();
    sort(slots1.begin(), slots1.end());
    sort(slots2.begin(), slots2.end());

    vector<pair<int, int>> candidates;
    for (auto& slot1 : slots1) {
      int s1 = slot1[0], e1 = slot1[1];
      if (e1 - s1 < duration) continue;

      auto it = upper_bound(slots2.begin(), slots2.end(), s1, [](int s, const vector<int>& slot) {
        return s < slot[0];
      });
      if (it == slots2.begin()) continue;
      --it;

      auto& slot2 = *it;
      int s2 = slot2[0], e2 = slot2[1];
      if (e2 - s1 < duration) continue;
      candidates.emplace_back(s1, s1 + duration);
    }
    for (auto& slot2 : slots2) {
      int s2 = slot2[0], e2 = slot2[1];
      if (e2 - s2 < duration) continue;

      auto it = upper_bound(slots1.begin(), slots1.end(), s2, [](int s, const vector<int>& slot) {
        return s < slot[0];
      });
      if (it == slots1.begin()) continue;
      --it;

      auto& slot1 = *it;
      int s1 = slot1[0], e1 = slot1[1];
      if (e1 - s2 < duration) continue;
      candidates.emplace_back(s2, s2 + duration);
    }

    if (candidates.empty()) return {};
    sort(candidates.begin(), candidates.end());
    return {candidates[0].first, candidates[0].second};
  }
};
