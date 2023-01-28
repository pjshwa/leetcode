const int MAX = 1e4;

class SummaryRanges {
  set<pair<int, int>> current;
  int use[MAX + 1], e2s[MAX + 1];

public:
  SummaryRanges() {
    memset(use, 0, sizeof(use));
  }

  void addNum(int value) {
    if (use[value]) return;

    if (value > 0 && use[value - 1]) {
      if (value < MAX && use[value + 1]) {
        auto it1 = current.lower_bound({e2s[value - 1], e2s[value - 1]});
        int s = it1->first;

        auto it2 = current.lower_bound({value + 1, value + 1});
        int e = it2->second;

        current.erase(it1);
        current.erase(it2);
        current.insert({s, e});
        e2s[e] = s;
      }
      else {
        auto it = current.lower_bound({e2s[value - 1], e2s[value - 1]});
        auto [s, _] = *it;

        current.erase(it);
        current.insert({s, value});
        e2s[value] = s;
      }
    }
    else {
      if (value < MAX && use[value + 1]) {
        auto it = current.lower_bound({value + 1, value + 1});
        auto [_, e] = *it;

        current.erase(it);
        current.insert({value, e});
        e2s[e] = value;
      }
      else {
        current.insert({value, value});
        e2s[value] = value;
      }
    }
    use[value] = 1;
  }

  vector<vector<int>> getIntervals() {
    vector<vector<int>> ret;
    for (auto &p : current) ret.push_back({p.first, p.second});
    return ret;
  }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
