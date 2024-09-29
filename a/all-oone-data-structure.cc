const int MAXV = 5e4;

class AllOne {
  unordered_set<string> K[MAXV + 1];
  unordered_map<string, int> V;
  deque<int> freqs;

  void reconcile(int from, int to) {
    if (from == 0) return freqs.push_front(to);
    if (to == 0) return freqs.pop_front();

    if (from < to) {
      auto it = upper_bound(freqs.begin(), freqs.end(), from);
      assert(it != freqs.begin());
      *prev(it) = to;
    } else {
      auto it = lower_bound(freqs.begin(), freqs.end(), from);
      assert(it != freqs.end());
      *it = to;
    }
  }

public:
  AllOne() {}

  void inc(string key) {
    if (V.count(key)) K[V[key]].erase(key);
    else V[key] = 0;
    ++V[key];
    K[V[key]].insert(key);

    reconcile(V[key] - 1, V[key]);
  }

  void dec(string key) {
    K[V[key]].erase(key);
    --V[key];
    if (V[key] == 0) V.erase(key);
    else K[V[key]].insert(key);

    reconcile(V[key] + 1, V[key]);
  }

  string getMaxKey() {
    if (freqs.empty()) return "";
    return *K[freqs.back()].begin();
  }

  string getMinKey() {
    if (freqs.empty()) return "";
    return *K[freqs.front()].begin();
  }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
