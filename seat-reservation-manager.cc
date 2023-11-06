class SeatManager {
  set<int> U;

public:
  SeatManager(int n) {
    for (int i = 1; i <= n; ++i) {
      U.insert(i);
    }
  }
  
  int reserve() {
    int v = *U.begin();
    U.erase(U.begin());
    return v;
  }
  
  void unreserve(int seatNumber) {
    U.insert(seatNumber);
  }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
 