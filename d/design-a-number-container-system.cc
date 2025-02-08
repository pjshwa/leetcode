class NumberContainers {
  unordered_map<int, int> by_index;
  unordered_map<int, set<int>> by_number;

public:
  NumberContainers() {}
  
  void change(int index, int number) {
    if (by_index.count(index)) {
      by_number[by_index[index]].erase(index);
    }
    by_index[index] = number;
    by_number[number].insert(index);
  }
  
  int find(int number) {
    if (by_number.count(number) && !by_number[number].empty()) {
      return *by_number[number].begin();
    }
    return -1;
  }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
