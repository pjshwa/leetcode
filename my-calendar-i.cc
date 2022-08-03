class MyCalendar {
  set<int> all_times, start_times, end_times;
public:
  MyCalendar() {
  }
  
  bool book(int start, int end) {
    auto it1 = all_times.upper_bound(start);
    auto it2 = all_times.lower_bound(end);

    // No overlappings & allocated in empty space
    if (it1 == it2 && (it1 == all_times.end() || start_times.count(*it1))) {
      // Merge segments
      bool sc = end_times.count(start), ec = start_times.count(end);
      if (sc) {
        if (ec) {
          start_times.erase(end);
          all_times.erase(end);
          end_times.erase(start);
          all_times.erase(start);
        }
        else {
          end_times.erase(start);
          all_times.erase(start);
          end_times.insert(end);
          all_times.insert(end);
        }
      }
      else if (ec) {
        start_times.erase(end);
        all_times.erase(end);
        start_times.insert(start);
        all_times.insert(start);
      }
      else {
        all_times.insert(start);
        all_times.insert(end);
        start_times.insert(start);
        end_times.insert(end);
      }

      return true;
    }
    return false;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
