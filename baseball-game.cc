class Solution {
public:
  int calPoints(vector<string>& ops) {
    stack<int> s;

    for (auto& op : ops) {
      if (op == "+") {
        int p1 = s.top(); s.pop();
        int p2 = s.top(); s.pop();
        s.push(p2); s.push(p1); s.push(p1 + p2);
      }
      else if (op == "D") s.push(s.top() * 2);
      else if (op == "C") s.pop();
      else s.push(stoi(op));
    }

    int ans = 0;
    while (!s.empty()) {
      ans += s.top();
      s.pop();
    }

    return ans;
  }
};
