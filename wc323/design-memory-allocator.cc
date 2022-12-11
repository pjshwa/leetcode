class Allocator {
  vector<int> memory;
  int n;
public:
  Allocator(int n) {
    memory = vector<int>(n, 0);
    this->n = n;
  }
  
  int allocate(int size, int mID) {
    int streak = 0;
    for (int i = 0; i < n; i++) {
      if (memory[i] == 0) streak++;
      else streak = 0;

      if (streak == size) {
        for (int j = i - size + 1; j <= i; j++) memory[j] = mID;
        return i - size + 1;
      }
    }
    return -1;
  }
  
  int free(int mID) {
    int freed = 0;
    for (int i = 0; i < n; i++) {
      if (memory[i] == mID) memory[i] = 0, freed++;
    }
    return freed;
  }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */