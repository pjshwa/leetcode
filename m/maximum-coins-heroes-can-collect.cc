class Solution {
public:
  vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
    int heroes_cnt = heroes.size(), monsters_cnt = monsters.size();

    vector<pair<int, long long>> pf_monsters_with_reward;
    for (int i = 0; i < monsters_cnt; ++i) pf_monsters_with_reward.emplace_back(monsters[i], coins[i]);
    sort(pf_monsters_with_reward.begin(), pf_monsters_with_reward.end());

    for (int i = 1; i < monsters_cnt; ++i) {
      pf_monsters_with_reward[i].second += pf_monsters_with_reward[i - 1].second;
    }

    vector<long long> ans;
    for (int hero_health : heroes) {
      int l = 0, r = monsters_cnt;
      while (l < r) {
        int mid = (l + r) / 2;

        if (pf_monsters_with_reward[mid].first <= hero_health) l = mid + 1;
        else r = mid;
      }

      if (l == 0) ans.push_back(0);
      else ans.push_back(pf_monsters_with_reward[l - 1].second);
    }
    return ans;
  }
};
