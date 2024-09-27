using pii = pair<int, int>;

class MyCalendarTwo {
  vector<pii> intervals1, intervals2;

  pii calc_overlap(pii& a, pii& b) {
    return {max(a.first, b.first), min(a.second, b.second)};
  }

  bool is_overlap(pii& a, pii& b) {
    return a.first < b.second && b.first < a.second;
  }

public:
  MyCalendarTwo() {
  }

  bool book(int start, int end) {
    pii I = {start, end};
    for (auto& O : intervals2) {
      if (is_overlap(I, O)) return false;
    }

    vector<pii> overlaps;
    for (auto& O : intervals1) {
      if (!is_overlap(I, O)) continue;
      intervals2.push_back(calc_overlap(I, O));
    }

    intervals1.push_back(I);
    return true;
  }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
