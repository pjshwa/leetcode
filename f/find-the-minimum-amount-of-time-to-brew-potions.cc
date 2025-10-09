using ll = long long;

class Solution {
public:
  ll minTime(vector<int>& skill, vector<int>& mana) {
    int N = skill.size(), M = mana.size();
    vector<ll> L(N); L[0] = skill[0] * mana[0];
    for (int i = 1; i < N; ++i) L[i] = L[i - 1] + skill[i] * mana[0];

    for (int p = 1; p < M; ++p) {
      ll addt = 0, curt = L[0];
      for (int i = 0; i < N; ++i) {
        addt = max(addt, L[i] - curt);
        curt += skill[i] * mana[p];
      }
      L[0] += addt + skill[0] * mana[p];
      for (int i = 1; i < N; ++i) L[i] = L[i - 1] + skill[i] * mana[p];
    }
    return L.back();
  }
};
