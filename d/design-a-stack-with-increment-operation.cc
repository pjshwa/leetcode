const int MAXN = 1000;

class CustomStack {
  int data[MAXN], dt[MAXN], maxSize, curSize;

public:
  CustomStack(int maxSize) {
    this->maxSize = maxSize;
    curSize = 0;
    memset(data, 0, sizeof(data));
    memset(dt, 0, sizeof(dt));
  }

  void push(int x) {
    if (curSize == maxSize) return;
    data[curSize++] = x;
  }

  int pop() {
    if (curSize == 0) return -1;

    --curSize;
    int ret = data[curSize] + dt[curSize];
    if (curSize > 0) dt[curSize - 1] += dt[curSize];
    dt[curSize] = 0;
    return ret;
  }

  void increment(int k, int val) {
    if (curSize == 0) return;

    int idx = min(k, curSize) - 1;
    dt[idx] += val;
  }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
