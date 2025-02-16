class MRUQueue {
  vector<int> q;
public:
  MRUQueue(int n) {
    for (int i = 1; i <= n; ++i) q.push_back(i);
  }
  
  int fetch(int k) {
    int idx = k - 1;
    int val = q[idx];
    q.erase(q.begin() + idx);
    q.push_back(val);
    return val;
  }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
