class Solution {
public:
  int minimumPushes(string word) {
    map<char, int> tal;
    for (char c : word) ++tal[c];
    vector<int> cnts;
    for (auto& [_, cnt] : tal) cnts.push_back(cnt);
    sort(cnts.begin(), cnts.end(), greater<>());

    int cost = 0, dt = 0;
    for (int i = 0; i < cnts.size(); ++i) {
      if (i % 8 == 0) ++dt;
      cost += dt * cnts[i];
    }
    return cost;
  }
};
