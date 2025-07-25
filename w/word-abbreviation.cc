class Solution {
public:
  vector<string> wordsAbbreviation(vector<string>& words) {
    vector<string> ans;

    map<pair<string, int>, vector<string>> M;
    for (string& w : words) {
      int Z = w.size();
      if (Z <= 3) continue;
      M[{w.substr(0, 1) + w.substr(Z - 1, 1), Z}].push_back(w);
    }

    map<string, int> V;
    for (auto& [_, vv] : M) {
      int Z = vv.size();
      sort(vv.begin(), vv.end());
      for (int i = 0; i < Z; ++i) {
        string S = vv[i]; int ovl = 0;
        for (int j : {i - 1, i + 1}) {
          if (j < 0 || j >= Z) continue;
          string T = vv[j]; int l = 0;
          while (l < S.size() && S[l] == T[l]) ++l;
          ovl = max(ovl, l);
        }
        V[S] = ovl;
      }
    }

    for (auto& w : words) {
      if (w.size() <= 3) {
        ans.push_back(w);
        continue;
      }

      int ovl = V[w]; string T = "";
      for (int i = 0; i <= ovl; ++i) T.push_back(w[i]);
      int abbr = w.size() - ovl - 2;
      if (abbr > 1) {
        T += to_string(abbr);
        T.push_back(w.back());
        ans.push_back(T);
      } else {
        ans.push_back(w);
      }
    }
    return ans;
  }
};
