class Solution {
public:
  int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int N = students.size(), wait = 0;
    queue<int> Q; for (int s : students) Q.push(s);
    reverse(sandwiches.begin(), sandwiches.end());
    while (Q.size() && wait < N) {
      int t = Q.front(); Q.pop();
      if (t == sandwiches.back()) sandwiches.pop_back(), wait = 0;
      else Q.push(t), ++wait;
    }
    return Q.size();
  }
};
