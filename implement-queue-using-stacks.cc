class MyQueue {
  stack<int> F, B;

  void move_if_empty() {
    if (!F.empty()) return;

    while (!B.empty()) {
      F.push(B.top());
      B.pop();
    }
  }

public:
  MyQueue() {
  }

  void push(int x) {
    B.push(x);
  }

  int pop() {
    move_if_empty();

    int ret = F.top();
    F.pop();
    return ret;
  }

  int peek() {
    move_if_empty();

    return F.top();
  }

  bool empty() {
    return F.empty() && B.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
