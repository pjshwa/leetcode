class Solution {
public:
  string rankTeams(vector<string>& votes) {
    int R[26][26] = {}, L = votes[0].size();
    for (auto& vote : votes) {
      for (int i = 0; i < L; ++i) ++R[vote[i] - 'A'][i];
    }

    string ans = votes[0];
    sort(ans.begin(), ans.end(), [&](char a, char b) {
      for (int i = 0; i < L; ++i) {
        if (R[a - 'A'][i] != R[b - 'A'][i]) return R[a - 'A'][i] > R[b - 'A'][i];
      }
      return a < b;
    });
    return ans;
  }
};
