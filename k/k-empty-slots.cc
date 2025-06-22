class Solution {
public:
  int kEmptySlots(vector<int>& bulbs, int k) {
    set<int> cur; int N = bulbs.size();
    for (int i = 0; i < N; ++i) {
      int b = bulbs[i]; cur.insert(b);
      auto it = cur.find(b);
      if (it != cur.begin() && b - *prev(it) == k + 1) return i + 1;
      auto nxt = next(it);
      if (nxt != cur.end() && *nxt - b == k + 1) return i + 1;
    }
    return -1;
  }
};
