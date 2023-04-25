class SmallestInfiniteSet {
  int R; set<int> L;
public:
  SmallestInfiniteSet() {
    R = 1;
  }
  
  int popSmallest() {
    if (L.empty()) return R++;
    else {
      int res = *L.begin();
      L.erase(L.begin());
      return res;
    }
  }
  
  void addBack(int num) {
    if (num >= R) return;
    L.insert(num);
  }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
