using ll = long long;
using pii = pair<int, int>;

template<ll P, ll M> struct Hashing {
  vector<ll> H, B;
  void build(const string &S){
    H.resize(S.size()+1);
    B.resize(S.size()+1);
    B[0] = 1;
    for(int i=1; i<=S.size(); i++) H[i] = (H[i-1] * P + S[i-1]) % M;
    for(int i=1; i<=S.size(); i++) B[i] = B[i-1] * P % M;
  }
  ll sub(int s, int e){
    ll res = (H[e] - H[s-1] * B[e-s+1]) % M;
    return res < 0 ? res + M : res;
  }
};

constexpr int P1 = 1299709, M1 = 1'000'000'007;
constexpr int P2 = 1301021, M2 = 1'000'000'009;

class HashedString {
  Hashing<P1, M1> H1;
  Hashing<P2, M2> H2;

public:
  HashedString(const string &S){
    H1.build(S);
    H2.build(S);
  }

  ll sub(int s, int e) {
    if (s > e) return -1;
    return H1.sub(s, e) * M2 + H2.sub(s, e);
  }
};

class StringWP {
  vector<int> str, plen;
  int n;

  void manacher() {
    int r = -1, p = -1;
    for (int i = 0; i < n; ++i) {
      if (i <= r) plen[i] = min((2 * p - i >= 0) ? plen[2 * p - i] : 0, r - i);
      else plen[i] = 0;

      while (
        i - plen[i] - 1 >= 0 && i + plen[i] + 1 < n &&
        str[i - plen[i] - 1] == str[i + plen[i] + 1]
      ) plen[i] += 1;

      if (i + plen[i] > r) {
        r = i + plen[i];
        p = i;
      }
    }
  }

public:
  StringWP(string& s) {
    n = (s.size() << 1) + 1;
    str.resize(n);
    plen.resize(n);

    for (int i = 0; i < n; i++) {
      if (i % 2) str[i] = -1;
      else str[i] = s[i / 2];
    }

    manacher();
  }

  StringWP(vector<int>& s) {
    n = (s.size() << 1) + 1;
    str.resize(n);
    plen.resize(n);

    for (int i = 0; i < n; i++) {
      if (i % 2) str[i] = -1;
      else str[i] = s[i / 2];
    }

    manacher();
  }

  bool is_palindrome(int s, int e) {
    if (s > e) return true;
    s = (s - 1) << 1;
    e = (e - 1) << 1;
    return e - (s + e) / 2 <= plen[(s + e) / 2];
  }

};

class Solution {
  vector<StringWP> v;
  vector<HashedString> hvf, hvb;
  
public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    for (auto& w : words) {
      v.push_back(StringWP(w));

      string wr = w;
      reverse(wr.begin(), wr.end());

      hvf.push_back(HashedString(w));
      hvb.push_back(HashedString(wr));
    }

    vector<vector<int>> ans;
    int n = words.size();
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
      int ssz = words[i].size(), tsz = words[j].size();
      if (ssz <= tsz) {
        if (v[j].is_palindrome(1, tsz - ssz) && hvb[i].sub(1, ssz) == hvf[j].sub(tsz - ssz + 1, tsz)) {
          ans.push_back({i, j});
        }
        if (v[j].is_palindrome(ssz + 1, tsz) && hvb[i].sub(1, ssz) == hvf[j].sub(1, ssz)) {
          ans.push_back({j, i});
        }
      }
      else {
        if (v[i].is_palindrome(tsz + 1, ssz) && hvb[j].sub(1, tsz) == hvf[i].sub(1, tsz)) {
          ans.push_back({i, j});
        }
        if (v[i].is_palindrome(1, ssz - tsz) && hvb[j].sub(1, tsz) == hvf[i].sub(ssz - tsz + 1, ssz)) {
          ans.push_back({j, i});
        }
      }
    }

    return ans;
  }
};
