class BrowserHistory {
  vector<string> H;
  int idx;

public:
  BrowserHistory(string homepage) {
    H.push_back(homepage);
    idx = 0;
  }

  void visit(string url) {
    while (H.size() > idx + 1) {
      H.pop_back();
    }
    H.push_back(url);
    idx++;
  }

  string back(int steps) {
    idx = max(0, idx - steps);
    return H[idx];
  }

  string forward(int steps) {
    idx = min((int)H.size() - 1, idx + steps);
    return H[idx];
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
