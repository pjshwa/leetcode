class MyCircularDeque {
  int N, s, e, sz, D[1000];

public:
  MyCircularDeque(int k) {
    N = k, s = 0, e = 0, sz = 0;
  }

  bool insertFront(int value) {
    if (isFull()) return false;
    int ns = (s - 1 + N) % N;
    D[ns] = value; s = ns; ++sz;
    return true;
  }

  bool insertLast(int value) {
    if (isFull()) return false;
    int ne = (e + 1) % N;
    D[e] = value; e = ne; ++sz;
    return true;
  }

  bool deleteFront() {
    if (isEmpty()) return false;
    s = (s + 1) % N; --sz;
    return true;
  }

  bool deleteLast() {
    if (isEmpty()) return false;
    e = (e - 1 + N) % N; --sz;
    return true;
  }

  int getFront() {
    return isEmpty() ? -1 : D[s];
  }

  int getRear() {
    return isEmpty() ? -1 : D[(e - 1 + N) % N];
  }

  bool isEmpty() {
    return sz == 0;
  }

  bool isFull() {
    return sz == N;
  }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
