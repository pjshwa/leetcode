class Bitset {
  bool v[100'000];
  int size, ccnt = 0;
  bool flipped = false;
public:
  Bitset(int size) {
    this->size = size;
    memset(v, 0, sizeof(v));
  }
  
  void fix(int idx) {
    if (flipped) {
      if (!v[idx]) return;
      v[idx] = false;
      ccnt--;

    }
    else {
      if (v[idx]) return;
      v[idx] = true;
      ccnt++;
    }
  }
  
  void unfix(int idx) {
    if (flipped) {
      if (v[idx]) return;
      v[idx] = true;
      ccnt++;

    }
    else {
      if (!v[idx]) return;
      v[idx] = false;
      ccnt--;
    }
  }
  
  void flip() {
    flipped = !flipped;
  }
  
  bool all() {
    if (flipped) return ccnt == 0;
    else return ccnt == size;
  }
  
  bool one() {
    if (flipped) return ccnt != size;
    else return ccnt != 0;
  }
  
  int count() {
    if (flipped) return size - ccnt;
    else return ccnt;
  }
  
  string toString() {
    string res = "";
    if (flipped) {
      for (int i = 0; i < size; i++) {
        if (v[i]) res += '0';
        else res += '1';
      }
    }
    else {
      for (int i = 0; i < size; i++) {
        if (v[i]) res += '1';
        else res += '0';
      }
    }
    return res;
  }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
 