using ll = long long;

class Solution {
public:
  vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
    int Z = req_skills.size(), N = people.size();

    ll d[1 << Z];
    memset(d, -1, sizeof(d)); d[0] = 0;
    vector<int> masks(N, 0);

    for (int i = 0; i < N; i++) {
      for (auto skill : people[i]) {
        int idx = find(req_skills.begin(), req_skills.end(), skill) - req_skills.begin();
        masks[i] |= 1 << idx;
      }

      for (int pstate = (1 << Z) - 1; pstate >= 0; pstate--) {
        if (d[pstate] == -1) continue;

        int cstate = pstate | masks[i];
        int pcnt = __builtin_popcountll(d[pstate]);
        int ccnt = __builtin_popcountll(d[cstate]);
        if (d[cstate] == -1 || pcnt + 1 < ccnt) {
          d[cstate] = d[pstate] | (1LL << i);
        }
      }
    }

    vector<int> ans;
    for (int i = 0; i < N; i++) {
      if (d[(1 << Z) - 1] & (1LL << i)) ans.push_back(i);
    }
    return ans;
  }
};
