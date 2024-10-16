class FirstUnique {
  map<int, int> t;
  int ptr = 0;
  vector<int> q;

public:
  FirstUnique(vector<int>& nums) {
    for (int x : nums) add(x);
  }

  int showFirstUnique() {
    if (ptr == q.size()) return -1;
    return q[ptr];
  }

  void add(int value) {
    ++t[value]; q.push_back(value);
    while (ptr < q.size() && t[q[ptr]] > 1) ++ptr;
  }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
