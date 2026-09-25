#include <bits/stdc++.h>
using namespace std;

struct R {
  vector<string> els;
  R() {}
  R(const vector<string>& els) : els(els) {}

  void merge(const R& other) {
    set<string> s(els.begin(), els.end());
    for (const string& b : other.els) s.insert(b);
    els = vector<string>(s.begin(), s.end());
  }

  void cross(const R& other) {
    vector<string> res;
    for (const string& a : els) for (const string& b : other.els) {
      res.push_back(a + b);
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    els = res;
  }
};

class Solution {
public:
  vector<string> braceExpansionII(string expression) {
    struct Frame {
      R sum, term{{""}};
    };
    vector<Frame> stack(1);

    for (char c : expression) {
      if (c == '{') {
        stack.emplace_back();
      } else if (c == ',') {
        stack.back().sum.merge(stack.back().term);
        stack.back().term = R({""});
      } else if (c == '}') {
        stack.back().sum.merge(stack.back().term);
        R group = stack.back().sum; stack.pop_back();
        stack.back().term.cross(group);
      } else {
        stack.back().term.cross(R({string(1, c)}));
      }
    }
    stack.back().sum.merge(stack.back().term);
    return stack.back().sum.els;
  }
};
