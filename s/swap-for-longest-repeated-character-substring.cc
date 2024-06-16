class Solution {
public:
  int maxRepOpt1(string text) {
    int T[256]{};
    for (char c : text) ++T[c];

    int r = 0, ans = 0, N = text.size();
    map<char, int> C;
    for (int l = 0; l < N; ++l) {
      while (r < N) {
        ++C[text[r]]; int minv = N;
        for (auto& [_, v] : C) minv = min(minv, v);

        int ok = C.size() <= 2;
        if (C.size() == 2 && minv > 1) ok = 0;

        if (ok) ++r;
        else {
          if (--C[text[r]] == 0) C.erase(text[r]);
          break;
        }
      }

      if (C.size() == 1) ans = max(ans, r - l);
      else {
        char a = C.begin()->first, b = next(C.begin())->first;
        vector<char> U;
        if (C[a] == 1) U.emplace_back(b);
        if (C[b] == 1) U.emplace_back(a);
        for (char c : U) ans = max(ans, min(T[c], r - l));
      }

      if (--C[text[l]] == 0) C.erase(text[l]);
    }
    return ans;
  }
};
