#pragma GCC optimize("Ofast")
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// begin deepsigh
#define min(x,y) ({ __typeof__(x) __var0 = x; __typeof__(y) __var1 = y; __var0 < __var1 ? __var0 : __var1; })
#define max(x,y) ({ __typeof__(x) __var0 = x; __typeof__(y) __var1 = y; __var0 < __var1 ? __var1 : __var0; })
static const int ENABLEFASTIO = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
// end deepsigh

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
bool updmin(T& a, T b) {
  if(b < a) {
    a = b;
    return true;
  }
  return false;
}
template<class T>
bool updmax(T& a, T b) {
  if(b > a) {
    a = b;
    return true;
  }
  return false;
}
template<class Fun>
class y_combinator_result {
  Fun fun_;
public:
  template<class T>
  explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

  template<class ...Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

// END NO SAD
// REMEMBER CLEAR GLOBAL STATE
// REMEMBER READ THE PROBLEM STATEMENT AND DON'T SOLVE A DIFFERENT PROBLEM
// REMEMBER LOOK FOR RANDOM UNINTUITIVE DETAILS IN THE PROBLEM
// remember hidden T factor of 1e2
// read the bounds for stupid cases
// did you restart your editor
// pushing back vectors is garbage, preinitialize them
// function calls are not free
struct disjoint_set {
  vector<int> p, sz;
  disjoint_set(int n) {
    p.resize(n); fill(all(p), -1);
    sz.resize(n); fill(all(sz), 1);
  }
  int find(int x) {
    return p[x] < 0 ? x : (p[x] = find(p[x]));
  }
  int getsz(int x) {
    return sz[find(x)];
  }
  bool merge(int x, int y) {
    // x goes to y
    x = find(x);
    y = find(y);
    if(x == y) return false;
    p[x] = y;
    sz[y] += sz[x];
    return true;
  }
};

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        disjoint_set dsu(sz(words));
        int lhs = sz(words);
        int rhs = 1;
        unordered_map<int, int> dp;
        vector<int> seen;
        for(int i = 0; i < sz(words); i++) {
          int curr = 0;
          for(auto out2: words[i]) curr |= (1 << (out2 - 'a'));
          if(dp.count(curr)) {
            if(dsu.merge(i, dp[curr])) {
              lhs--;
              rhs = max(rhs, dsu.getsz(i));
            }
          }
          else {
            seen.pb(curr);
            dp[curr] = i;
          }
        }
        for(int a = 0; a < sz(seen); a++) {
          int out = seen[a];
          for(int i = 0; i < 26; i++) {
            if(out & (1 << i)) {
              // replace
              for(int j = 0; j < i; j++) {
                if(out & (1 << j)) continue;
                int ncand = out ^ (1 << i) ^ (1 << j);
                if(dp.count(ncand)) {
                  int idx = dp[ncand];
                  if(dsu.merge(dp[out], idx)) {
                    lhs--;
                    rhs = max(rhs, dsu.getsz(idx));
                  }
                }
              }
            }
            else {
              // add
              int ncand = out | (1 << i);
              if(dp.count(ncand)) {
                int idx = dp[ncand];
                if(dsu.merge(dp[out], idx)) {
                  lhs--;
                  rhs = max(rhs, dsu.getsz(idx));
                }
              }
            }
          }
        }
        vector<int> ret;
        ret.pb(lhs);
        ret.pb(rhs);
        return ret;
    }
};
