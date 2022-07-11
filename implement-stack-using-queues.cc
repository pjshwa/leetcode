class MyStack {
  queue<int> qf, qb;
public:
  MyStack() {
  }
  
  void push(int x) {
    qf.push(x);
  }
  
  int pop() {
    while (qf.size() > 1) qb.push(qf.front()), qf.pop();
    int ret = qf.front();
    qf.pop();
    while (qb.size()) qf.push(qb.front()), qb.pop();
    return ret;
  }
  
  int top() {
    int ret;
    while (qf.size()) {
      qb.push(qf.front());
      if (qf.size() == 1) ret = qf.front();
      qf.pop();
    }
    while (qb.size()) qf.push(qb.front()), qb.pop();
    return ret;
  }
  
  bool empty() {
    return qf.empty();
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
