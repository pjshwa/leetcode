class MyStack {
  queue<int> Q1;
  int size;

public:
  MyStack() {
    size = 0;
  }

  void push(int x) {
    Q1.push(x); size++;
  }

  int pop() {
    for (int i = 0; i < size - 1; i++) {
      int f = Q1.front(); Q1.pop();
      Q1.push(f);
    }

    int ret = Q1.front(); Q1.pop();

    size--;
    return ret;
  }

  int top() {
    for (int i = 0; i < size - 1; i++) {
      int f = Q1.front(); Q1.pop();
      Q1.push(f);
    }

    int ret = Q1.front(); Q1.pop();
    Q1.push(ret);

    return ret;
  }

  bool empty() {
    return size == 0;
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
