class Solution {
public:
  string clearStars(string s) {
    int N = s.size();
    vector<int> ban(N);

    using T = pair<int, int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    for (int i = 0; i < N; ++i) {
      if (s[i] == '*') {
        int t = -pq.top().second; pq.pop();
        ban[t] = 1;
      } else {
        pq.push({s[i], -i});
      }
    }

    string ans = "";
    for (int i = 0; i < N; ++i) {
      if (s[i] != '*' && !ban[i]) ans += s[i];
    }
    return ans;
  }
};
