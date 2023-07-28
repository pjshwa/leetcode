
#define all(x) (x).begin(), (x).end()
#define compress(x) sort(all(x)), (x).erase(unique(all(x)), (x).end())
#define getidx(v, x) (lower_bound(all(v), x) - v.begin())

using ll = long long;

const ll MAX = 20000;

class Solution {
  vector<int> graph[MAX + 1];
  int cnt[MAX + 1];
  vector<ll> qs;
  vector<int> pr{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
  bool vis[MAX + 1];
  int gcount;

  void dfs(int v) {
    vis[v] = true;
    gcount += cnt[v];
    for (int u : graph[v]) {
      if (!vis[u]) dfs(u);
    }
  }

  ll lpow(ll x, ll y, ll m) {
    ll r = 1;
    x %= m;
    while (y) {
      if (y & 1) r = (r * x) % m;
      x = (x * x) % m;
      y >>= 1;
    }
    return r;
  }

public:
  vector<int> groupStrings(vector<string>& words) {
    int n = words.size();
    int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;

    for (int j = 0; j < n; j++) {
      ll val1 = 1, val2 = 1;
      for (int i = 0; i < words[j].size(); i++) {
        val1 = (val1 * pr[words[j][i] - 'a']) % MOD1;
        val2 = (val2 * pr[words[j][i] - 'a']) % MOD2;
      }
      qs.push_back(val1 * MOD2 + val2);
    }
    compress(qs);

    for (int j = 0; j < n; j++) {
      ll val1 = 1, val2 = 1;
      for (int i = 0; i < words[j].size(); i++) {
        val1 = (val1 * pr[words[j][i] - 'a']) % MOD1;
        val2 = (val2 * pr[words[j][i] - 'a']) % MOD2;
      }
      int id = getidx(qs, val1 * MOD2 + val2);
      cnt[id]++;
    }

    for (int i = 0; i < n; i++) {
      ll oval1 = 1, oval2 = 1;
      for (int j = 0; j < words[i].size(); j++) {
        oval1 = (oval1 * pr[words[i][j] - 'a']) % MOD1;
        oval2 = (oval2 * pr[words[i][j] - 'a']) % MOD2;
      }
      ll oval = oval1 * MOD2 + oval2;
      for (int j = 0; j < words[i].size(); j++) {
        for (int k = 0; k < 26; k++) {
          ll nval1 = oval1, nval2 = oval2;
          nval1 = (nval1 * pr[k]) % MOD1;
          nval2 = (nval2 * pr[k]) % MOD2;
          nval1 = (nval1 * lpow(pr[words[i][j] - 'a'], MOD1 - 2, MOD1)) % MOD1;
          nval2 = (nval2 * lpow(pr[words[i][j] - 'a'], MOD2 - 2, MOD2)) % MOD2;

          int id = getidx(qs, oval);
          if (!binary_search(all(qs), nval1 * MOD2 + nval2)) continue;
          int nid = getidx(qs, nval1 * MOD2 + nval2);
          graph[id].push_back(nid);
          graph[nid].push_back(id);
        }
      }

      for (int j = 0; j < words[i].size(); j++) {
        ll nval1 = oval1, nval2 = oval2;
        nval1 = (nval1 * lpow(pr[words[i][j] - 'a'], MOD1 - 2, MOD1)) % MOD1;
        nval2 = (nval2 * lpow(pr[words[i][j] - 'a'], MOD2 - 2, MOD2)) % MOD2;

        int id = getidx(qs, oval);
        if (!binary_search(all(qs), nval1 * MOD2 + nval2)) continue;
        int nid = getidx(qs, nval1 * MOD2 + nval2);
        graph[id].push_back(nid);
        graph[nid].push_back(id);
      }
    }

    int cc = 0, mgcount = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < qs.size(); i++) {
      if (!vis[i]) {
        cc++;
        gcount = 0;
        dfs(i);
        mgcount = max(mgcount, gcount);
      }
    }

    return {cc, mgcount};
  }
};
