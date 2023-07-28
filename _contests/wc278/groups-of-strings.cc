using ll = long long;

const ll MAX = 20000;
int parent[MAX + 1], usz[MAX + 1];

int Find(int x) {
  if (x == parent[x]) return x;
  else {
    int p = Find(parent[x]);
    parent[x] = p;
    return p;
  }
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);

  if (x == y) return;

  parent[y] = x;
  usz[x] += usz[y];
}

class Solution {

public:
  vector<int> groupStrings(vector<string>& words) {
    int n = words.size();
    for (int i = 0; i < n; i++) parent[i] = i, usz[i] = 1;

    unordered_map<int, int> d;
    vector<int> states;
    for (int i = 0; i < n; i++) {
      int state = 0;
      for (char& c : words[i]) {
        int d = c - 'a';
        state |= (1 << d);
      }

      if (d.count(state)) Union(i, d[state]);
      else states.push_back(state);
      d[state] = i;
    }

    for (int& state : states) {
      int oi = d[state];
      for (int i = 0; i < 26; i++) {
        if (state & (1 << i)) {
          int nstate = state & ~(1 << i);
          for (int j = 0; j < 26; j++) {
            if (state & (1 << j)) continue;
            if (!d.count(nstate | (1 << j))) continue;
            Union(oi, d[nstate | (1 << j)]);
          }
        }
        else {
          if (!d.count(state | (1 << i))) continue;
          Union(oi, d[state | (1 << i)]);
        }
      }
    }

    set<int> groups;
    int mgcount = 0;
    for (int i = 0; i < n; i++) {
      groups.insert(Find(i));
      mgcount = max(mgcount, usz[Find(i)]);
    }

    return {(int)groups.size(), mgcount};
  }
};
