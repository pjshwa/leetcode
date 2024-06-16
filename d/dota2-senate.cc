class Solution {
public:
  string predictPartyVictory(string senate) {
    queue<int> dq, rq;
    int n = senate.size();
    for (int i = 0; i < n; i++) {
      if (senate[i] == 'R') rq.push(i);
      else dq.push(i);
    }

    int ban[n]; memset(ban, 0, sizeof ban);
    for (int i = 0;; i++) {
      if (dq.empty()) return "Radiant";
      if (rq.empty()) return "Dire";

      int j = i % n;
      if (ban[j]) continue;

      while (rq.front() < j) rq.push(rq.front() + n), rq.pop();
      while (dq.front() < j) dq.push(dq.front() + n), dq.pop();

      if (senate[j] == 'D') {
        ban[rq.front() % n] = 1;
        rq.pop();
      }
      else {
        ban[dq.front() % n] = 1;
        dq.pop();
      }
    }
    return "";
  }
};
