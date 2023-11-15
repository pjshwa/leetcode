class MovingAverage {
  queue<int> q;
  int size, sum;

public:
  MovingAverage(int size) {
    this->size = size;
    this->sum = 0;
  }
  
  double next(int val) {
    if (q.size() == this->size) {
      this->sum -= q.front();
      q.pop();
    }
    q.push(val);
    this->sum += val;
    return (double)this->sum / q.size();
  }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
 